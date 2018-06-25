#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include"Score.h"
#include<iostream>
#include<list>
#include<string>
#include<array>
using namespace std;
using namespace score;
int main()
{
	using namespace nana;
	string name;
	Score score;
	Score score2;
	Score score3;
	Score score4;
	Score score5;
	int num=30;
	string num1;
	array<string, 5>aNames;
	array<int, 5>anums;
	
	score.scoreName = "luciano";
	score.score = 20;
	
	score2.scoreName = "juan jose";
	score2.score = 50;

	score3.scoreName = "pedro";
	score3.score = 120;

	score4.scoreName = "carlos";
	score4.score = 25;

	score5.scoreName = "diego";
	score5.score = 65;

	ScoreManagement scoreManagment;
	scoreManagment.addScore(score);
	scoreManagment.addScore(score2);
	scoreManagment.addScore(score3);
	scoreManagment.addScore(score4);
	scoreManagment.addScore(score5);
	
	int index = 0;
	scoreManagment.sortList();
	list<Score>listScore=scoreManagment.returnScoreList();

	for (list<Score>::iterator it = listScore.begin(); it != listScore.end(); ++it) {
		Score scores = *it;
		aNames[index] = scores.scoreName;
		anums[index] = scores.score;
		cout << "nums " << anums[index]<<endl;
		index++;
	}

	

	//Define a form.
	form fm{API::make_center(600,400)};

	//Define a label and display a text.
	
	label lab1{ fm, };
	label lab2{ fm };
	label lab3{ fm };
	label lab4{ fm };
	label lab5{ fm };

	label labNum1{ fm };
	label labNum2{ fm };
	label labNum3{ fm };
	label labNum4{ fm };
	label labNum5{ fm };

	lab1.caption("<bold red size=16>" +aNames[0]);
	lab2.caption("<bold red size=16>" + aNames[1]);
	lab3.caption("<bold red size=16>" + aNames[2]);
	lab4.caption("<bold red size=16>" + aNames[3]);
	lab5.caption("<bold red size=16>" + aNames[4]);
	
	labNum1.caption("<bold red size=16>" + to_string(anums[0]));
	labNum2.caption("<bold red size=16>" + to_string(anums[1]));
	labNum3.caption("<bold red size=16>" + to_string(anums[2]));
	labNum4.caption("<bold red size=16>" + to_string(anums[3]));
	labNum5.caption("<bold red size=16>" + to_string(anums[4]));
	//lab.format(true);
	lab1.format(true);
	lab2.format(true);
	lab3.format(true);
	lab4.format(true);
	lab5.format(true);
	
	labNum1.format(true);
	labNum2.format(true);
	labNum3.format(true);
	labNum4.format(true);
	labNum5.format(true);
	//Define a button and answer the click event.
	
	//Layout management
	
	fm.div("<vertical text gap=5 margin=20 arrange=50> <vertical num margin=20 gap=5 arrange=50 >");
	//fm.div("<abc>");
	fm["text"] << lab1;
	fm["num"] << labNum1;
	fm["text"] << lab2;
	fm["num"] << labNum2;
	fm["text"] << lab3;
	fm["num"] << labNum3;
	fm["text"] << lab4;
	fm["num"] << labNum4;
	fm["text"] << lab5;
	fm["num"] << labNum5;
	place plc(fm);
	fm.collocate();

	//Show the form
	fm.show();

	//Start to event loop process, it blocks until the form is closed.
	exec();
}