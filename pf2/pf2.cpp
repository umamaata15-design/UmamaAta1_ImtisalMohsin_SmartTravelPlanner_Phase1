// pf2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <iomanip>
	using namespace std;
	
	const int min_travellers = 1;
	const int max_travellers = 10;
	const int min_days = 1;
	const int max_days = 30;

	int displayMenu();
	void displayDestinations();
	int selectDestination();
	int getTravellers();
	int getDuration();
	int selectActivities(string & names);
	int getBudget();
	int getAccommodationRate(int destination);
	int getTransportRate(int destination);
	int getFoodRate(int destination);
	string getDestinationName(int destination);
	int calcuaccommondation(int travellers, int days, int rate);
	int calcuTransport(int travellers, int rate);
	int calcufood(int travellers, int days, int rate);
	int calcuactivities(int travellers, int activitysumrate);
	int calcutotal(int accomm, int trans, int food, int activities);
	int checkbudget(int budget, int total);
	void displayresult(int destination, int travellers, int days, string activitiesname,
		int accommondations, int transport, int food, int activitiescost,
		int total, int budget, int withinbudget);

	// Function 1: Display Menu
	int displayMenu()
	{
		int choice;
		cout << "Smart Travel Planner" << endl;
		cout << "1. Plan a Trip" << endl;
		cout << "2. View available Destinations" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		return choice;
	}

	// Shows all destinations with their rates
	void displayDestinations()
	{
		cout << "1 Murree Accommodation: 9000 Transport: 4000 Food: 3000" << endl;
		cout << "2 Hunza Accommodation: 12000 Transport: 15000 Food: 3000" << endl;
		cout << "3 Swat Accommodation: 8000 Transport: 6000 Food: 2000" << endl;
		cout << "4 Naran Accommodation: 10000 Transport: 8000 Food: 2500" << endl;
	}

	// Function 2: Select Destination
	int selectDestination()
	{
		int destination;
		displayDestinations();
		cout << "Enter your Destination (1-4): ";
		cin >> destination;
		while (destination < 1 || destination > 4)
		{
			cout << "Invalid destination! Enter again: ";
			cin >> destination;
		}
		return destination;
	}

	// Function 3: Number of Travellers
	int getTravellers()
	{
		int travellers;
		cout << "Enter number of travellers (1-10): ";
		cin >> travellers;
		while (travellers < min_travellers || travellers > max_travellers)
		{
			cout << "Invalid number! Travellers must be between 1 and 10" << endl;
			cout << "Enter again: ";
			cin >> travellers;
		}
		return travellers;
	}

	// Function 4: Trip Duration
	int getDuration()
	{
		int days;
		cout << "Enter number of days (1-30): ";
		cin >> days;
		while (days < min_days || days > max_days)
		{
			cout << "Duration must be between 1 and 30" << endl;
			cout << "Enter duration again: ";
			cin >> days;
		}
		return days;
	}

	// Function 5: Activity Selection
	int selectActivities(string & names)
	{
		bool sight = false, hike = false, boat = false;
		bool museum = false, adventure = false;
		int sum = 0;
		int choice;
		names = "";

		do
		{
			cout << "1 Sightseeing 600" << endl;
			cout << "2 Hiking 1200" << endl;
			cout << "3 Boating 1100" << endl;
			cout << "4 Museum 350" << endl;
			cout << "5 Adventure 1800" << endl;
			cout << "Enter activity (1-5 to add, 0 to finish): ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				if (sight) cout << "Already added." << endl;
				else { sight = true; sum = sum + 600; names = names + "Sightseeing "; }
				break;
			case 2:
				if (hike) cout << "Already added." << endl;
				else { hike = true; sum = sum + 1200; names = names + "Hiking "; }
				break;
			case 3:
				if (boat) cout << "Already added." << endl;
				else { boat = true; sum = sum + 1100; names = names + "Boating "; }
				break;
			case 4:
				if (museum) cout << "Already added." << endl;
				else { museum = true; sum = sum + 350; names = names + "Museum "; }
				break;
			case 5:
				if (adventure) cout << "Already added." << endl;
				else { adventure = true; sum = sum + 1800; names = names + "Adventure "; }
				break;
			case 0:
				break;
			default:
				cout << "Error: enter a number from 0 to 5." << endl;
			}
		} while (choice != 0);

		if (names == "")
			names = "None";
		return sum;
	}

	// Function 6: Get Budget
	int getBudget()
	{
		int budget;
		cout << "Enter your budget: ";
		cin >> budget;
		while (budget <= 0)
		{
			cout << "Invalid Budget! It must be greater than 0" << endl;
			cout << "Enter again: ";
			cin >> budget;
		}
		return budget;
	}

	// Rates and name of a destination
	int getAccommodationRate(int destination)
	{
		switch (destination)
		{
		case 1:
			return 9000;
		case 2:
			return 12000;
		case 3:
			return 8000;
		default:
			return 10000;
		}
	}
	int getTransportRate(int destination)
	{
		switch (destination)
		{
		case 1: 
			return 4000;
		case 2:
			return 15000;
		case 3:
			return 6000;
		default:
			return 8000;
		}
	}
	int getFoodRate(int destination)
	{
		switch (destination)
		{
		case 1:
			return 3000;
		case 2:
			return 3000;
		case 3:
			return 2000;
		default:
			return 2500;
		}
	}
	string getDestinationName(int destination)
	{
		switch (destination)
		{
		case 1:
			return "Murree";
		case 2:
			return "Hunza";
		case 3:
			return "Swat";
		default:
			return "Naran";
		}
	}

	// Function 7: Calculate cost
	int calcuaccommondation(int travellers, int days, int rate)
	{
		int rooms = (travellers + 1) / 2;
		int night = days - 1;
		return rooms * night * rate;
	}
	int calcuTransport(int travellers, int rate)
	{
		return travellers * rate;
	}
	int calcufood(int travellers, int days, int rate)
	{
		return travellers * days * rate;
	}
	int calcuactivities(int travellers, int activitysumrate)
	{
		return travellers * activitysumrate;
	}
	int calcutotal(int accomm, int trans, int food, int activities)
	{
		return accomm + trans + food + activities;
	}

	// Function 8: Check budget (1 = within, 0 = over)
	int checkbudget(int budget, int total)
	{
		if (total <= budget)
			return 1;
		else
			return 0;
	}

	// Function 9: Display Result
	void displayresult(int destination, int travellers, int days, string activitiesname,
		int accommondations, int transport, int food, int activitiescost,
		int total, int budget, int withinbudget)
	{
		cout << "Destination: " << getDestinationName(destination) << endl;
		cout << "Travellers: " << travellers << endl;
		cout << "Duration: " << days << " days" << endl;
		cout << "Activities: " << activitiesname << endl;
		cout << "Accommodation: " << accommondations << endl;
		cout << "Transport: " << transport << endl;
		cout << "Food: " << food << endl;
		cout << "Activities cost: " << activitiescost << endl;
		cout << "Total estimated cost: " << total << endl;
		cout << "Budget: " << budget << endl;
		if (withinbudget == 1)
			cout << "WITHIN BUDGET - remaining PKR " << budget - total << endl;
		else
			cout << "OVER BUDGET - exceeded by PKR " << total - budget << endl;
	}

	// Function 10: Main
	int main()
	{
		int choice;
		int destination, travellers, days, budget;
		int activitysumrate;
		string activitiesname;
		int accommondations, transport, food, activitiescost, total;
		int withinbudget;

		do
		{
			choice = displayMenu();
			switch (choice)
			{
			case 1:
				destination = selectDestination();
				travellers = getTravellers();
				days = getDuration();
				activitysumrate = selectActivities(activitiesname);
				budget = getBudget();

				accommondations = calcuaccommondation(travellers, days, getAccommodationRate(destination));
				transport = calcuTransport(travellers, getTransportRate(destination));
				food = calcufood(travellers, days, getFoodRate(destination));
				activitiescost = calcuactivities(travellers, activitysumrate);
				total = calcutotal(accommondations, transport, food, activitiescost);

				withinbudget = checkbudget(budget, total);
				displayresult(destination, travellers, days, activitiesname, accommondations,
					transport, food, activitiescost, total, budget, withinbudget);
				break;
			case 2:
				displayDestinations();
				break;
			case 3:
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Invalid choice!" << endl;
			}
		} while (choice != 3);
		return 0;
	}

	

