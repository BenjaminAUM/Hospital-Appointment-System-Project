// Hospital
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int checkup, day, hour, total;
	char referral;
	double surcharge = 0, base = 0;
	string slot_time;
	referral = 'N';
	referral = 'n';
	referral = 'Y';
	referral = 'y';

	cout << "Enter type (1=general, 2=Emergency, 3=Specialist): ";     //User input
	cin >> checkup;

	if (checkup == 0 || checkup >= 4)                   //Validates input
	{
		cout << "Invalid input" << endl;
		return 0;
	}

	cout << "Enter day (1=Mon, 2=Tues, 3=Wed...7=Sun): ";      //User input
	cin >> day;

	if (day == 0 || day >= 8)                           //Validates input
	{
		cout << "Invalid input" << endl;
		return 0;
	}

	cout << "Enter hour (0-23)";                   //User input
	cin >> hour;

	if (hour == 0 || hour >= 24)                         //Validates input
	{
		cout << "Invalid input" << endl;
		return 0;
	}

	if (checkup == 1)
	{
		base = 150;
		if (day == 6 || day == 7)
		{
			cout << "surcharge added";
			surcharge = 20;
		}
		else
		{

		}
		if (hour < 9)
		{
			string day_text = "??";

			switch (day)
			{
			case 1: day_text = "Mon";
				break;
			case 2:
				day_text = "Tue";
				break;
			case 3:
				day_text = "Wed";
				break;
			case 4:
				day_text = "Thu";
				break;
			case 5:
				day_text = "Fri";
				break;
			case 6:
				day_text = "Sat";
				break;
			case 7:
				day_text = "Sun";
				break;
			default:
				day_text = "??";
				break;
			}
			slot_time = day_text + " 09:00";
		}
		else if (hour >= 9 && hour < 17)
		{
			string day_text = "??";
			switch (day)
			{
			case 1: day_text = "Mon";
				break;
			case 2: day_text = "Tue";
				break;
			case 3: day_text = "Wed";
				break;
			case 4: day_text = "Thu";
				break;
			case 5: day_text = "Fri";
				break;
			case 6: day_text = "Sat";
				break;
			case 7: day_text = "Sun";
				break;
			default: day_text = "??";
				break;
			}
			slot_time = day_text + " " + to_string(hour + 1) + ":00";
		}
		else
		{
			int next_day = (day % 7) + 1;
			string day_text = "??";
			switch (next_day)
			{
			case 1: day_text = "Mon";
				break;
			case 2: day_text = "Tue";
				break;
			case 3: day_text = "Wed";
				break;
			case 4: day_text = "Thu";
				break;
			case 5: day_text = "Fri";
				break;
			case 6: day_text = "Sat";
				break;
			case 7: day_text = "Sun";
				break;
			default: day_text = "??";
				break;
			}
			slot_time = day_text + " 09:00";
		}
	}

    else if (checkup == 2)
    {
		base = 250;
		if (hour >= 22 || hour < 6)
		{
			cout << "Surcharge added" << endl;
			surcharge = 50;
		}
		slot_time = "Immediate";
	
    }

	else if (checkup == 3)
	{
		base = 150;
		cout << "Referral? (Y/N): ";
		cin >> referral;

		if (referral == 'N' || referral == 'n')
		{
			cout << "surcharge added" << endl;
			surcharge = 40;
		}
		else if (day == 6 || day == 7)
		{
			slot_time = "Monday 10:00";
		}
		else if (hour < 9)
		{
			string day_text = "??";
			switch (day)
			{
			case 1: day_text = "Mon";
				break;
			case 2: day_text = "Tue";
				break;
			case 3: day_text = "Wed";
				break;
			case 4: day_text = "Thu";
				break;
			case 5: day_text = "Fri";
				break;
			case 6: day_text = "Sat";
				break;
			case 7: day_text = "Sun";
				break;
			default: day_text = "??";
				break;
			}
			slot_time = day_text + "09:00";
		}
		else if (hour >= 9 && hour < 17)
		{
			string day_text = "??";
			switch (day)
			{
			case 1: day_text = "Mon";
				break;
			case 2: day_text = "Tue";
				break;
			case 3: day_text = "Wed";
				break;
			case 4: day_text = "Thu";
				break;
			case 5: day_text = "Fri";
				break;
			case 6: day_text = "Sat";
				break;
			case 7: day_text = "Sun";
				break;
			default: day_text = "??";
				break;
			}
			slot_time = day_text + " " + to_string(hour + 1) + ":00";
		}
		else
		{
			cout << "Invalid service type\n";
			return 0;
		}
		
	}

	total = base + surcharge;
	cout << "---- Appointment Summary ----" << endl;
	cout << "Base Cost   : $" << base << endl;
	cout << "Surcharge   : $" << surcharge << endl;
	cout << "Total cost  : $" << total << endl;
	cout << "Next slot   : $" << slot_time << endl;
	cout << "       Have a nice day       " << endl;
	cout << "-----------------------------" << endl;

	return 0;
}