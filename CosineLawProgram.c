#include <stdio.h>
#include <math.h>

const double pi = 3.14159;
void cosineLawEq(double sdA, double sdB, double oppAng)
{
    printf("Enter one of the given sides: \n");
    scanf("%lf", &sdA);
    printf("Enter another given side: \n");
    scanf("%lf", &sdB);
    printf("Enter the angle opposite to the unknown side: \n");
    scanf("%lf", &oppAng);

    double sideC = sqrt((pow(sdA, 2) + pow(sdB, 2)) - ((2 * sdA * sdB) * cos(oppAng * pi/180)));
    printf("Side C (ROUNDED) is: %.2lf \n", sideC);
}

void findAngleCosine(double sdA, double sdB, double sdC)
{
    double angleC = (pow (sdC, 2) - pow(sdA, 2) - pow(sdB, 2)) / (-2 * sdA * sdB);
    angleC = acos(angleC); 
    angleC = angleC * (180/pi);
    printf("Angle C is: %.1lf \n", angleC);
}

int main()
{
    double sideA, sideB, opposingAngle, sideC;
    char yesOrNo;
    char whichABC;

    printf("Are you trying to find a Side or Angle? Type in S for side or A for angle: \n");
    scanf("%c", &yesOrNo);

    getchar();
    switch(yesOrNo)
    {
        case 'S':
        case 's':
            cosineLawEq(sideA, sideB, opposingAngle);
            break;

        case 'A':
        case 'a':
            printf("Which angle are you looking for?: \n");
            scanf("%c", &whichABC);
            
            printf("Enter side A please: \n");
            scanf("%lf", &sideA);
            printf("Enter side B please: \n");
            scanf("%lf", &sideB);
            printf("Enter side C please: \n");
            scanf("%lf", &sideC);

            if(whichABC == 'C' || whichABC == 'c')
            {  
                findAngleCosine(sideA, sideB, sideC);
            }
            else if(whichABC == 'B' || whichABC == 'b')
            {
                findAngleCosine(sideA, sideC, sideB);
            } 
            else if(whichABC == 'A' || whichABC == 'a')
            {
                findAngleCosine(sideB, sideC, sideA);
            }
            else
            {
                printf("Type in the valid letter please\n");
            }
            break;
        
        default:
            printf("Please type in either S or A \n "); 
            break; 
    }



}