// Program to track the shadow of a cloud
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const float Pi = 3.14159265359;
const float Fc = Pi / 12; //Factorial conversion for hours into radians
const float Dc = 180 / Pi; //Factorial conversion from radians to degrees

float Time;
float Sunx, Suny, Sunz;
float SunsAngle = 23.44 / Dc; // This will change depending on the day

bool Sunlight;
string Orientation;


int main()
{
	cout << "What time would you like to know the sunlight?" << endl;
	cin >> Time;  // Input for time
	cout << endl;

	float Rad = Time * Fc; //Conversion of hours to Pi

	int n = (Rad) / (2 * Pi); //Calculates Sun's revolutions 

	float DegZ = Dc * (SunsAngle); //Z angle in degrees
	float DegY = Dc * ((Rad)-n * (2 * Pi)); //Y angle in degrees

	if (DegY == 0) // Suns position On the Y axis
	{
		Orientation = " West";
		DegY = 0;
	}
	else if (DegY == 90)
	{
		Orientation = " North";
		DegY = 0;
	}
	else if (DegY == 180)
	{
		Orientation = " East";
		DegY = 0;
	}
	else if (DegY == 270)
	{
		Orientation = " South";
		DegY = 0;
	}
	else if (DegY > 0 && DegY < 90)
	{
		Orientation = " North of East";
	}
	else if (DegY > 90 && DegY < 180)
	{
		Orientation = " North of West";
		DegY = (DegY - 180) * (-1);
	}
	else if (DegY > 180 && DegY < 270)
	{
		Orientation = " South of West";
		DegY = DegY - 180;
	}
	else if (DegY > 270 && DegY < 360)
	{
		Orientation = " South of East";
		DegY = (DegY - 360) * (-1);
	}

	Sunx = cos(Rad); //Calculating Sun's x coordinates
	Suny = sin(Rad) * cos(SunsAngle); //Calculating Sun's y coordinates
	Sunz = sin(SunsAngle) * sin(Rad); //Calculating Sun's z coordinates


	if (Suny >= 0) // Time the sun is up
	{
		Sunlight = true;
	}

	else if (Suny < 0) // Time that sun is down
	{
		Sunlight = false;
	}

	cout << "Sun = " << Sunlight << ", Time = " << Time;  // Output time and sunlight I/O
	cout << fixed << setprecision(2) << ", SunX = " << Sunx << ", SunY = " << Suny << ", SunZ = " << Sunz << endl; // Sun's position
	cout << setprecision(1) << "\nSun is " << DegZ << " degrees from the horizon, and is " << DegY << " degrees" << Orientation << endl; // Sun's angle


		/* Cloud Simulation Exercise Begins */

	float x_1 = 0.7, x_2 = 0.8, y_1 = 0.5, y_2 = 0.6;

	float Cloud_1 = atan(y_1 / x_1);
	float Cloud_2 = atan(y_2 / y_2);

	if (Rad >= Cloud_1 && Rad <= Cloud_2)
	{
		Sunlight = false;
		cout << "Cloud's will contribute to shade during this time\n";
	}

	/* Cloud Simulation Exercise Ends */


	if (Sunlight == true)
	{
		cout << "\nSun at your location during this time\n" << endl; // Output sunlight is true
	}

	else if (Sunlight == false)
	{
		cout << "\nNo sun at your location\n" << endl; // Output sunlight is False
	}


}

