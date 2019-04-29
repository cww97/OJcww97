#include<cstdio>
using namespace std;
int limit,speed;
int main()
{
	printf("Enter the speed limit: ");
	scanf("%d",&limit);
	printf("Enter the recorded speed of the car: ");
	scanf("%d",&speed);
	if (speed<=limit)printf("Congratulations, you are within the speed limit");
	else if (speed-limit<=20)printf("You are speeding and your fine is $ %d",100);
	else if (speed-limit<=30)printf("You are speeding and your fine is $ %d",270);
	else printf("You are speeding and your fine is $ %d",500);
	return 0;
} 
