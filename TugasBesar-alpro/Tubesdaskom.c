#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to perform a single step of the Runge-Kutta fourth order method
void RK4_step(double *w, double h);

// Function describing the right-hand side of the equations of motion
void f(double *w, double *temp_vector);

// Function to initialize the vector w
void shoot(double theta, double v0, double *w);

// Function to calculate the motion of the projectile using RK4
void projectile_motion(double h, double theta, double *X_list, double *Y_list);

// Function to find the optimal initial shooting angle for maximum range
void find_optimal_angle(double h, double *theta_list, double *range_list, double *optimal_angle);

// Function to plot projectile trajectories for alternating shooting angles
void trajectories(double h);

int main() {
    // Constants
    const double g = 9.81;
    const double alpha = 2.5;
    const double a = 6.5e-3;
    const double T_0 = 288;
    const double m = 50;
    const double B = 2e-3;
    const double v_0 = 1640;
    const double V[2] = {0, 0}; // Wind speed

    // Parameters for optimization
    const double h = 0.1;

    // Variables
    double w[4];
    double theta_list[45];
    double range_list[45];
    double optimal_angle;

    // Find the optimal angle
    find_optimal_angle(h, theta_list, range_list, &optimal_angle);

    printf("The optimal angle is: %.2f degrees\n", optimal_angle);

    // Plot projectile range as a function of shooting angle
    printf("\nProjectile range as a function of shooting angle:\n");
    printf("--------------------------------------------\n");
    printf("%-15s%-15s\n", "Theta (degrees)", "Range (km)");
    for (int i = 0; i < 45; ++i) {
        printf("%-15.2f%-15.2f\n", theta_list[i], range_list[i] / 1000);
    }

    // Plot projectile trajectories for alternating shooting angles
    trajectories(h);

    return 0;
}

void RK4_step(double *w, double h) {
    double s1[4], s2[4], s3[4], s4[4];

    f(w, s1);
    f(w + (h / 2) * s1, s2);
    f(w + (h / 2) * s2, s3);
    f(w + h * s3, s4);

    for (int i = 0; i < 4; ++i) {
        w[i] += (h / 6) * (s1[i] + 2 * s2[i] + 2 * s3[i] + s4[i]);
    }
}

void f(double *w, double *temp_vector) {
    double k, s;

    temp_vector[0] = w[2];
    temp_vector[1] = w[3];

    k = (1 - a * w[1] / T_0);
    s = sqrt(pow(w[2] - V[0], 2) + pow(w[3] - V[1], 2));

    if (k > 0) {
        temp_vector[2] = -B / m * pow(k, alpha) * (w[2] - V[0]) * s;
        temp_vector[3] = -B / m * pow(k, alpha) * (w[3] - V[1]) * s - g;
    } else {
        temp_vector[2] = 0;
        temp_vector[3] = -g;
    }
}

void shoot(double theta, double v0, double *w) {
    w[2] = v0 * cos(theta * PI / 180);
    w[3] = v0 * sin(theta * PI / 180);
}

void projectile_motion(double h, double theta, double *X_list, double *Y_list) {
    double w[4];
    shoot(theta, V,0, w);

    int idx = 0;
    while (w[1] >= 0) {
        RK4_step(w, h);
        X_list[idx] = w[0];
        Y_list[idx] = w[1];
        ++idx;
    }
}

void find_optimal_angle(double h, double *theta_list, double *range_list, double *optimal_angle) {
    double record = 0;
    *optimal_angle = 0;

    for (double theta = 1; theta <= 90; theta += 2) {
        double x_list[1000], y_list[1000];
        projectile_motion(h, theta, x_list, y_list);

        double m = (y_list[999] - y_list[998]) / (x_list[999] - x_list[998]);
        double x_range = -y_list[999] / m + x_list[999];

        theta_list[(int)((theta - 1) / 2)] = theta;
        range_list[(int)((theta - 1) / 2)] = x_range;

        if (x_range >= record) {
            record = x_range;
            *optimal_angle = theta;
        }
    }

    // Rerun on a smaller interval for more precise approximation
    for (double theta_small = *optimal_angle - 2; theta_small <= *optimal_angle + 2; theta_small += 0.1) {
        double x_list[1000], y_list[1000];
        projectile_motion(h, theta_small, x_list, y_list);

        double m = (y_list[999] - y_list[998]) / (x_list[999] - x_list[998]);
        double x_range = -y_list[999] / m + x_list[999];

        if (x_range >= record) {
            record = x_range;
            *optimal_angle = theta_small;
        }
    }
}

void trajectories(double h) {
    printf("\nProjectile trajectories by alternating shooting angle:\n");
    printf("----------------------------------------------------\n");
    printf("%-20s%-20s\n", "Theta (degrees)", "Range (km)");

    double theta_list[10] = {30, 35, 40, 45, 50, 55, 60, 65, 70, 75};

    for (int i = 0; i < 10; ++i) {
        double x_list[1000], y_list[1000];
        projectile_motion(h, theta_list[i], x_list, y_list);

        printf("%-20.2f%-20.2f\n", theta_list[i], x_list[999] / 1000);
    }
}
