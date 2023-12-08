#include <stdio.h>
#include <math.h>
#define PI 3.14

double g = 9.81;
double alpha = 2.5;
double a = 6.5 * pow(10, -3);
double T_0 = 288;
double m = 50;
double B = 2 * pow(10, -3);
double v_0 = 1640;

double V[2] = {0, 0};

void f(double w[4], double temp_vector[4]) {
    temp_vector[0] = w[2];
    temp_vector[1] = w[3];

    double k = (1 - a * w[1] / T_0);
    double s = sqrt(pow(w[2] - V[0], 2) + pow(w[3] - V[1], 2));
    if (k > 0) {
        temp_vector[2] = -B / m * pow(k, alpha) * (w[2] - V[0]) * s;
        temp_vector[3] = -B / m * pow(k, alpha) * (w[3] - V[1]) * s - g;
    } else {
        temp_vector[2] = 0;
        temp_vector[3] = -g;
    }
}

void RK4_step(void (*f)(double[4], double[4]), double w[4], double h) {
    double s1[4], s2[4], s3[4], s4[4];
    double temp[4];

    f(w, s1);
    for (int i = 0; i < 4; i++) {
        temp[i] = w[i] + (h / 2) * s1[i];
    }
    f(temp, s2);
    for (int i = 0; i < 4; i++) {
        temp[i] = w[i] + (h / 2) * s2[i];
    }
    f(temp, s3);
    for (int i = 0; i < 4; i++) {
        temp[i] = w[i] + h * s3[i];
    }
    f(temp, s4);
    for (int i = 0; i < 4; i++) {
        w[i] = w[i] + (h / 6) * (s1[i] + 2 * s2[i] + 2 * s3[i] + s4[i]);
    }
}

void shoot(double theta, double v0, double w[4]) {
    w[2] = v0 * cos(theta * PI / 180);
    w[3] = v0 * sin(theta * PI / 180);
}

void projectile_motion(double h, double theta, double X_list[], double Y_list[]) {
    double w[4] = {0, 0, 0, 0};
    shoot(theta, v_0, w);
    int i = 0;
    while (w[1] >= 0) {
        RK4_step(f, w, h);
        X_list[i] = w[0];
        Y_list[i] = w[1];
        i++;
    }
}

void find_optimal_angle(double h, double theta_list[], double range_list[], double* optimal_angle) {
    double record = 0;
    *optimal_angle = 0;

    int index = 0;
    for (int theta = 1; theta < 90; theta += 2) {
        double x_list[1000], y_list[1000];
        projectile_motion(h, theta, x_list, y_list);

        double m = (y_list[index] - y_list[index - 1]) / (x_list[index] - x_list[index - 1]);
        double x_range = -y_list[index] / m + x_list[index];
        theta_list[index] = theta;
        range_list[index] = x_range;

        if (x_range >= record) {
            record = x_range;
            *optimal_angle = theta;
        }
        index++;
    }

    double theta_list_smaller[41];
    for (int i = 0; i < 41; i++) {
        theta_list_smaller[i] = *optimal_angle - 2 + i * 0.1;
    }
    for (int i = 0; i < 41; i++) {
        double x_list[1000], y_list[1000];
        projectile_motion(h, theta_list_smaller[i], x_list, y_list);

        double m = (y_list[index] - y_list[index - 1]) / (x_list[index] - x_list[index - 1]);
        double x_range = -y_list[index] / m + x_list[index];
        if (x_range >= record) {
            record = x_range;
            *optimal_angle = theta_list_smaller[i];
        }
    }
}

int main() {
    double theta_list[45], range_list[45], optimal_angle;
    find_optimal_angle(0.1, theta_list, range_list, &optimal_angle);
    printf("The optimal angle is: %.2f degrees\n", optimal_angle);
    for (int i = 0; i < 45; i++) {
        printf("%.2f ", theta_list[i]);
    }
    printf("\n");
    for (int i = 0; i < 45; i++) {
        printf("%.2f ", range_list[i]);
    }
    printf("\n");
    return 0;
}