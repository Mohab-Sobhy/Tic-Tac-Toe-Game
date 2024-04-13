#pragma once
class Board {
private:
	Game* gamePointer;
	int** board;
	bool AreThreeElementsEqual(int a, int b, int c); //check equality
public:
	Board(Game* pointer);
	/*
		create and intialize board values
		{0,0,0,0,0}
		{0,4,1,1,0}
		{0,1,1,1,0}
		{0,1,1,1,0}
		{0,0,0,0,0}
		0->Boundary | 1->Free | 2->X | 3->O | 4->Cursor
	*/
	void display();
	/*
		Print Board
	*/
	bool isEqualColumn(int column_num);
	/*
		Check columns equality
	*/
	bool isEqualRow(int row_num);
	/*
		Check rows equality
	*/
	bool isEqualDiameter(bool mainOrSecondry);
	/*
		Verify the equality of the diameters
	*/
};