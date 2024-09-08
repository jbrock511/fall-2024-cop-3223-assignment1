/*copied directly from the other assignment repo I made (thru girhub classroom)
sorry if any problems arise because of this*/

#include <math.h>
#include <stdio.h>
//defines Pi value as 3.14159
#define PI 3.14159

//Instructions: calculate width, height, distance, area, perimeter

//this will make the variables for the points, but without making them global
typedef struct {
    int x1;
    int x2;
    int y1;
    int y2;
} Points;

    Points* getPoints(){
        static Points nums;
        return &nums;
    }

    //note: no output because of void function
    void calculate_distance(){
        Points* nums = getPoints();
        static double distance = 0;
        //distance equation
        distance = sqrt(pow(nums->x2 - nums->x1, 2) + pow(nums->y2 - nums->y1, 2));
        printf("\nThe distance between the two points is %.3f\n", distance);
    }
    
    double getDistance(){
        Points* nums = getPoints();
        /*since distance is defined as static in the section above this, we cannot use it across the project
        thus, we get the following return*/
        return sqrt(pow(nums->x2 - nums->x1, 2) + pow(nums->y2 - nums->y1, 2));
    }
    
    //perimeter calculation
    double calculate_perimeter(){
        //will essentially remind the computer what distance means, since we didn't define it globally
        double distance = getDistance();
        double perimeter = fabs(2 * PI * distance - 2);
        printf("The perimeter of the city encompassed by your request is: %.3f \n", perimeter);
    }

    //area calculation
    double calculate_area(){
        double distance = getDistance();
        double area = PI * pow(distance / 2, 2) + 2;
        printf("The area of the city encompassed by your request is: %.3f\n", area);
    }

    //width calculation
    double calculate_width(){
        //this will pull the coordinates from earlier, woohoo!
        Points* nums = getPoints();
        double width = fabs(nums->x2 - nums->x1) + 2;
        printf("The width of the city encompassed by your request is: %.3f\n", width);
    }

    //height calculation
    double calculate_height(){
        Points* nums = getPoints();
        double height = fabs(nums->y2 - nums->y1) + 1;
        printf("The height of the city encompassed by your request is: %.3f\n", height);
    }

//main function will be used to house the defined values for the coordinate points
int main(){
    Points* nums = getPoints();
        nums->x1 = 2;
        nums->x2 = 2;
        nums->y1 = 1;
        nums->y2 = 2;

    //print functions below will define what points were entered
    printf("Point #1 entered: x1 = %d, x2 = %d\n", nums->x1, nums->x2);
    printf("Point #2 entered: y1 = %d, y2 = %d\n", nums->y1, nums->y2);

    //below is where I called all of the functions we defined previously in the code :-)

    calculate_distance();
    calculate_perimeter();
    calculate_area();
    calculate_width();
    calculate_height();

return 0;
}