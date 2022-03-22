#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string>name, stadium, town;
vector<string>fixtures, fixtures1, derbys, derbys1;


string names, stadia, towns, row, rows, line, lines;
int counter = 0, no_of_teams;


void csv_teams_file()
{
	string names, stadia, towns;
	ifstream team_csv;
	team_csv.open("teams.csv");

	//reading from the csv file
	if (!team_csv)
	{
		cout << "File not found\n";
		exit(0);
	}


	while (!team_csv.eof())
	{
		getline(team_csv, names, ',');
		name.push_back(names);

		getline(team_csv, towns, ',');
		town.push_back(towns);

		getline(team_csv, stadia, '\n');
		stadium.push_back(stadia);
	}
	team_csv.close();

}
void ReadFixtures()
{

	//reading from created files
	ifstream teamfixtures, teamfixtures1, derbyfixtures, derbyfixtures1;
	teamfixtures.open("fixtures.csv");
	teamfixtures1.open("fixtures1.csv");
	derbyfixtures.open("Derby.csv");
	derbyfixtures1.open("Derby1.csv");
	//leg 1 file
	if (!teamfixtures)
	{
		cout << "File not found";
		exit(0);
	}

	while (getline(teamfixtures, row, '\n'))
	{
		fixtures.push_back(row);
	}
	teamfixtures.close();

	//leg 2 file
	if (!teamfixtures1)
	{
		cout << "File not found";
		exit(0);
	}

	while (getline(teamfixtures1, rows, '\n'))
	{

		fixtures1.push_back(rows);
	}
	teamfixtures1.close();

	//leg 1 derby matches
	if (!derbyfixtures)
	{
		cout << "File not found";
		exit(0);
	}

	while (getline(derbyfixtures, line, '\n'))
	{

		derbys.push_back(line);
	}
	derbyfixtures.close();

	//leg 2 derby matches
	if (!derbyfixtures1)
	{
		cout << "File not found";
		exit(0);
	}

	while (getline(derbyfixtures1, lines, '\n'))
	{

		derbys1.push_back(lines);
	}
	derbyfixtures1.close();
}
void shuffleFixtures()
{
	for (int i = 0; i < fixtures.size(); i++)
	{
		random_shuffle(fixtures.begin(), fixtures.end());
	}

	for (int i = 0; i < fixtures1.size(); i++)
	{
		random_shuffle(fixtures1.begin(), fixtures1.end());
	}

	for (int i = 0; i < derbys.size(); i++)
	{
		random_shuffle(derbys.begin(), derbys.end());
	}
	for (int i = 0; i < derbys1.size(); i++)
	{
		random_shuffle(derbys1.begin(), derbys1.end());
	}
}
void populate()
{

	ofstream team_fixtures("Final Fixtures. txt");
	team_fixtures << "\n\n\t\t------------------------------------------*****FINAL FIXTURES*****-------------------------------------------------\n\n";
	cout << "\n\n\t\t------------------------------------*****FINAL FIXTURES*****----------------------------------------\n\n";

	for (int i = 0; i < fixtures.size(); i++)
	{

		cout << "\n\n\t***************************************Weekend #" << ++counter << "*****************************************\n\n";
		team_fixtures << "\n\n\t***************************************Weekend #" << counter << "*****************************************\n\n";

		cout << "\tGame 1\n" << fixtures[i] << "\t Leg 1" << endl;
		team_fixtures << "\tGame 1\n" << fixtures[i] << "\t Leg 1" << endl;

		cout << "\tGame 2\n" << fixtures1[i] << "\t Leg 2" << endl;
		team_fixtures << "\tGame 2\n" << fixtures1[i] << "\t Leg 2" << endl << endl;
	}
	for (int i = 0; i < derbys.size(); i++)
	{
		cout << "\n\n\t***************************************Weekend #" << ++counter << "*****************************************\n\n";
		team_fixtures << "\n\n\t***************************************Weekend #" << counter << "*****************************************\n\n";

		cout << "\tGame 1\n" << derbys[i] << "\t Leg 1" << endl;
		team_fixtures << "\tGame 1\n" << derbys[i] << "\t Leg 1" << endl;

		cout << "\tGame 2\n" << derbys1[i] << "\t Leg 2" << endl;
		team_fixtures << "\tGame 2\n" << derbys1[i] << "\t Leg 2" << endl << endl;
	}

}

int main() {
	csv_teams_file();

	int no_of_teams = name.size() - 1;

	//Generating Fixtures
	ofstream matches("fixtures.csv");//leg1
	ofstream matches1("fixtures1.csv"); //leg2
	ofstream derby("Derby.csv");//leg1
	ofstream derby1("Derby1.csv");//leg2
	for (auto i = 1; i < no_of_teams; i++)
	{
		for (auto j = i + 1; j < no_of_teams; j++)//leg 1 and 2 matches
		{
			if (town[i] != town[j])
			{
				matches << name[i] << " \t(" << town[i] << ")\tvs\t " << name[j] << "\t(" << town[j] << ")  VENUE: " << stadium[i] << " - " << town[i] << endl;
				matches1 << name[j] << " \t(" << town[j] << ")\tvs\t" << name[i] << "\t(" << town[i] << ")  VENUE:  " << stadium[j] << " - " << town[j] << endl;
			}
			else//derbies
			{

				derby << name[i] << " \t(" << town[i] << ")\tvs\t " << name[j] << "\t(" << town[j] << ")  VENUE: " << stadium[i] << " - " << town[i] << endl;
				derby1 << name[j] << " \t(" << town[j] << ")\tvs\t" << name[i] << "\t(" << town[i] << ")  VENUE:  " << stadium[j] << " - " << town[j] << endl;
			}
		}
	}
	matches.close();
	matches1.close();
	derby.close();
	derby1.close();

	ReadFixtures();
	shuffleFixtures();

	cout << "\n\t---------------------------------------------------------WELCOME TO ABC PREMIER LEAGUE--------------------------------------------\n";
	populate();
	cout << "\n\n\t----------------------------------------------------------------THANK YOU-----------------------------------------------------------\n";
	

	system("pause>nul");
	main();
	system("cls");

}
