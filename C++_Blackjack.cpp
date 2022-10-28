#include <iostream>
#include <string>
#include <ctime>

using namespace std;


string cards[52] = {     "HA","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
						 "DA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
						 "CA","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK",
						 "SA","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK" };


string cardValues[52] = {    "1","2","3","4","5","6","7","8","9","10","10","10","10",
						  "1","2","3","4","5","6","7","8","9","10","10","10","10",
						  "1","2","3","4","5","6","7","8","9","10","10","10","10",
						  "1","2","3","4","5","6","7","8","9","10","10","10","10" };


int Phand,Phand1, Phand2, Phand3, Phand4, Phand5,Phand6;
int Dhand, Dhand1, Dhand2, Dhand3, Dhand4, Dhand5;

string Pcard1, Pcard2, Pcard3, Pcard4, Pcard5, Pcard6;
string Dcard1, Dcard2, Dcard3, Dcard4, Dcard5, Dcard6;

int HitCounter;

bool GameOver = false;
bool PBlackjack = false;
bool DBlackjack = false;
bool Plose = false;
bool Dlose = false;
bool DrawGame = false;

//I shuffled both together because when they are shuffled together their locations will be same. So I can determine the values of the cards easily.
//Example: card[0]="D5"  cardValues[0]="5" first elements of arrays have same location (both[0]) . Convert the string to int and that's it.
void Shuffle(string deck[],int len) {

	string temp,temp2;
	int randomIndex = 0;

	for (int i = 0; i < len; i++) {

		randomIndex = rand() % len;

		//shuffle cards
		temp = cards[i];
		cards[i] = cards[randomIndex];
		cards[randomIndex] = temp;
		
		//shuffle cardValues
		temp2 = cardValues[i];
		cardValues[i] = cardValues[randomIndex];
		cardValues[randomIndex] = temp2;

	}

}

void Hit(char HorS) {
	

	if (HorS == 'h' || HorS == 'H') {

		HitCounter++;

		if (HitCounter == 1) {
			Pcard3 = cards[4];

			Phand3 = stoi(cardValues[4]);

			Phand = Phand1 + Phand2 + Phand3;

			if (Phand > 21 && (Phand1 == 11 || Phand2 == 11)) {

				if (Phand1 == 11) {
					Phand1 = 1;
				}
				else if (Phand2 == 11) {
					Phand2 = 1;
				}

				Phand = Phand1 + Phand2 + Phand3;
			}
			
			if (Phand > 21) {
				cout << endl;
				cout << "You went bust. You lose" << endl;
				Plose = true;
			}

			cout << endl;
			cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
			cout << "\t\t\t " << Dcard1 << " " << Dcard2 << "\t\t\t " << Pcard1 << " " << Pcard2 <<" "<<Pcard3 << endl;
			cout << "\t\t\t " << Dhand1 << " " << Dhand2 << "\t\t\t " << Phand1 << " " << Phand2 <<" "<<Phand3 << endl;
			cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
			cout << endl;
		}
		else if (HitCounter == 2) {

			Pcard4 = cards[5];

			Phand4 = stoi(cardValues[5]);

			Phand = Phand1 + Phand2 + Phand3 + Phand4;

			if (Phand > 21 && (Phand1 == 11 || Phand2 == 11)) {

				if (Phand1 == 11) {
					Phand1 = 1;
				}
				else if (Phand2 == 11) {
					Phand2 = 1;
				}

				Phand = Phand1 + Phand2 + Phand3;
			}

			if (Phand > 21) {
				cout << endl;
				cout << "You went bust. You lose" << endl;
				Plose = true;
			}


			cout << endl;
			cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
			cout << "\t\t\t " << Dcard1 << " " << Dcard2 << "\t\t\t " << Pcard1 << " " << Pcard2<<" "<<Pcard3<<" "<<Pcard4 << endl;
			cout << "\t\t\t " << Dhand1 << " " << Dhand2 << "\t\t\t " << Phand1 << " " << Phand2 <<" "<<Phand3<<" "<<Phand4 << endl;
			cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
			cout << endl;
		}
		else if (HitCounter == 3) {

			Pcard5 = cards[6];

			Phand5 = stoi(cardValues[6]);

			Phand = Phand1 + Phand2 + Phand3 + Phand4 + Phand5;

			if (Phand > 21 && (Phand1 == 11 || Phand2 == 11)) {

				if (Phand1 == 11) {
					Phand1 = 1;
				}
				else if (Phand2 == 11) {
					Phand2 = 1;
				}

				Phand = Phand1 + Phand2 + Phand3;
			}

			if (Phand > 21) {
				cout << endl;
				cout << "You went bust. You lose" << endl;
				Plose = true;
			}


			cout << endl;
			cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
			cout << "\t\t\t " << Dcard1 << " " << Dcard2 << "\t\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3 << " " << Pcard4<<" "<<Pcard5 << endl;
			cout << "\t\t\t " << Dhand1 << " " << Dhand2 << "\t\t\t " << Phand1 << " " << Phand2 << " " << Phand3 << " " << Phand4<<" "<<Phand5 << endl;
			cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
			cout << endl;
		}
		else if (HitCounter == 4) {

			Pcard6 = cards[7];

			Phand6 = stoi(cardValues[7]);

			Phand = Phand1 + Phand2 + Phand3 + Phand4 + Phand5 + Phand6;

			if (Phand > 21 && (Phand1 == 11 || Phand2 == 11)) {

				if (Phand1 == 11) {
					Phand1 = 1;
				}
				else if (Phand2 == 11) {
					Phand2 = 1;
				}

				Phand = Phand1 + Phand2 + Phand3;
			}

			if (Phand > 21) {
				cout << endl;
				cout << "You went bust. You lose" << endl;
				Plose = true;
			}


			cout << endl;
			cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
			cout << "\t\t\t " << Dcard1 << " " << Dcard2 << "\t\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3 << " " << Pcard4 << " " << Pcard5<<" "<<Pcard6 << endl;
			cout << "\t\t\t " << Dhand1 << " " << Dhand2 << "\t\t\t " << Phand1 << " " << Phand2 << " " << Phand3 << " " << Phand4 << " " << Phand5 <<" "<<Phand6 << endl;
			cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
			cout << endl;
		}
		

	}

}

void WhoWin();

void Stand(char HorS) {

	if (HorS == 's' || HorS == 'S') {

		if (HitCounter == 0) {

			
			 if (Dhand <= 16) {

				Dcard3 = cards[4];

				Dhand3 = stoi(cardValues[4]);


				Dhand = Dhand1 + Dhand2 + Dhand3;

				cout << endl;
				cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
				cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << "\t\t " << Pcard1 << " " << Pcard2 << endl;
				cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 <<"\t\t\t "<< Phand1 << " " << Phand2 << endl;
				cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
				cout << endl;

				if (Dhand > 21 && (Dhand1 == 11 || Dhand2 == 11)) {

					if (Dhand1 == 11) {
						Dhand1 = 1;
					}
					else if (Dhand2 == 11) {
						Dhand2 = 1;
					}

					Dhand = Dhand1 + Dhand2 + Dhand3;

				}

				if (Dhand <= 16) {
					Dcard4 = cards[5];

					Dhand4 = stoi(cardValues[5]);


					Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4;

					cout << endl;
					cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
					cout << "\t\t\t " << Dcard1 << " " << Dcard2 <<" "<<Dcard3<<" "<<Dcard4 << "\t\t " << Pcard1 << " " << Pcard2 << endl;
					cout << "\t\t\t " << Dhand1 << " " << Dhand2 <<" "<<Dhand3<<" "<<Dhand4 << "\t\t " << Phand1 << " " << Phand2 << endl;
					cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
					cout << endl;



					if (Dhand <= 16) {
						Dcard5 = cards[6];

						Dhand5 = stoi(cardValues[6]);


						Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4 + Dhand5;

						cout << endl;
						cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
						cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << " " << Dcard4<<" "<<Dcard5 << "\t\t " << Pcard1 << " " << Pcard2 << endl;
						cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << " " << Dhand4<<" "<<Dhand5 << "\t\t "<< Phand1 << " "<< Phand2 << endl;
						cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
						cout << endl;

						if (Dhand >= 17) {

							Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4 + Dhand5;

							WhoWin();
						}
					}
					else if (Dhand >= 17) {

						Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4;

						WhoWin();
					}
				}
				else if (Dhand >= 17 ) {

					Dhand = Dhand1 + Dhand2 + Dhand3;

					WhoWin();
				}

			}
			else if (Dhand >= 17) {

				Dhand = Dhand1 + Dhand2  ;

				WhoWin();
			}

		}
		else if (HitCounter == 1) {

			if (Dhand <= 16) {
				Dcard3 = cards[5];

				Dhand3 = stoi(cardValues[5]);


				Dhand = Dhand1 + Dhand2 + Dhand3;

				cout << endl;
				cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
				cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << "\t\t " << Pcard1 << " " << Pcard2 <<" "<<Pcard3<< endl;
				cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << "\t\t\t "<< Phand1 << " " << Phand2<<" "<<Phand3 << endl;
				cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
				cout << endl;

				if (Dhand > 21 && (Dhand1 == 11 || Dhand2 == 11)) {

					if (Dhand1 == 11) {
						Dhand1 = 1;
					}
					else if (Dhand2 == 11) {
						Dhand2 = 1;
					}

					Dhand = Dhand1 + Dhand2 + Dhand3;
				}

				if (Dhand <= 16) {
					Dcard4 = cards[6];

					Dhand4 = stoi(cardValues[6]);


					Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4;

					cout << endl;
					cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
					cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << " " << Dcard4 << "\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3 << endl;
					cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << " " << Dhand4 << "\t\t " << Phand1 << " " << Phand2 << " " << Phand3 << endl;
					cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
					cout << endl;

					if (Dhand <= 16) {
						Dcard5 = cards[7];

						Dhand5 = stoi(cardValues[7]);


						Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4 + Dhand5;

						cout << endl;
						cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
						cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << " " << Dcard4 << " " << Dcard5 << "\t\t " << Pcard1 << " " << Pcard2<<" "<<Pcard3 << endl;
						cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << " " << Dhand4 << " " << Dhand5 << "\t\t " << Phand1 << " " << Phand2<<" "<<Phand3 << endl;
						cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
						cout << endl;

						if (Dhand >= 17) {

							Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4 + Dhand5;

							WhoWin();
						}
					}
					else if (Dhand >= 17) {

						Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4;

						WhoWin();
					}
				}
				else if (Dhand >= 17) {

					Dhand = Dhand1 + Dhand2 + Dhand3;

					WhoWin();
				}

			}
			else if (Dhand >= 17) {

				Dhand = Dhand1 + Dhand2 ;

				WhoWin();
			}
		}
		else if (HitCounter == 2) {

			if (Dhand <= 16) {

				Dcard3 = cards[6];

				Dhand3 = stoi(cardValues[6]);


				Dhand = Dhand1 + Dhand2 + Dhand3;

				cout << endl;
				cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
				cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << "\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3 <<" " << Pcard4 << endl;
				cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << "\t\t\t " << Phand1 << " " << Phand2 << " " << Phand3 <<" "<<Phand4 << endl;
				cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
				cout << endl;

				if (Dhand > 21 && (Dhand1 == 11 || Dhand2 == 11)) {

					if (Dhand1 == 11) {
						Dhand1 = 1;
					}
					else if (Dhand2 == 11) {
						Dhand2 = 1;
					}

					Dhand = Dhand1 + Dhand2 + Dhand3;
				}

				if (Dhand <= 16) {
					Dcard4 = cards[7];

					Dhand4 = stoi(cardValues[7]);


					Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4;

					cout << endl;
					cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
					cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << " " << Dcard4 << "\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3<<" "<<Pcard4 << endl;
					cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << " " << Dhand4 << "\t\t " << Phand1 << " " << Phand2 << " " << Phand3<<" "<<Phand4 << endl;
					cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
					cout << endl;

					if (Dhand <= 16) {
						Dcard5 = cards[8];

						Dhand5 = stoi(cardValues[8]);


						Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4 + Dhand5;

						cout << endl;
						cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
						cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << " " << Dcard4 << " " << Dcard5 << "\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3<<" "<<Pcard4 << endl;
						cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << " " << Dhand4 << " " << Dhand5 << "\t\t " << Phand1 << " " << Phand2 << " " << Phand3<<" "<<Phand4 << endl;
						cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
						cout << endl;

						if (Dhand >= 17) {

							Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4 + Dhand5;

							WhoWin();
						}
					}
					else if (Dhand >= 17) {

						Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4;

						WhoWin();
					}
				}
				else if (Dhand >= 17) {

					Dhand = Dhand1 + Dhand2 + Dhand3;
					
					WhoWin();
				}

				
			}
			else if (Dhand >= 17) {

				Dhand = Dhand1 + Dhand2;

				WhoWin();

			}
		}
		else if (HitCounter == 3) {

			if (Dhand <= 16) {

				Dcard3 = cards[7];

				Dhand3 = stoi(cardValues[7]);


				Dhand = Dhand1 + Dhand2 + Dhand3;

				cout << endl;
				cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
				cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << "\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3 << " " << Pcard4 <<" "<<Pcard5 << endl;
				cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 <<"\t\t\t "<< Phand1 << " " << Phand2 << " " << Phand3 << " " << Phand4<<" "<<Phand5 << endl;
				cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
				cout << endl;

				if (Dhand > 21 && (Dhand1 == 11 || Dhand2 == 11)) {

					if (Dhand1 == 11) {
						Dhand1 = 1;
					}
					else if (Dhand2 == 11) {
						Dhand2 = 1;
					}

					Dhand = Dhand1 + Dhand2 + Dhand3;
				}

				if (Dhand <= 16) {
					Dcard4 = cards[8];

					Dhand4 = stoi(cardValues[8]);


					Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4;

					cout << endl;
					cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
					cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << " " << Dcard4 << "\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3 << " " << Pcard4<<" "<<Pcard5 << endl;
					cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << " " << Dhand4 << "\t\t " << Phand1 << " " << Phand2 << " " << Phand3 << " " << Phand4<<" "<<Phand5 << endl;
					cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
					cout << endl;

					if (Dhand <= 16) {
						Dcard5 = cards[9];

						Dhand5 = stoi(cardValues[9]);


						Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4 + Dhand5;

						cout << endl;
						cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards " << endl;
						cout << "\t\t\t " << Dcard1 << " " << Dcard2 << " " << Dcard3 << " " << Dcard4 << " " << Dcard5 << "\t\t " << Pcard1 << " " << Pcard2 << " " << Pcard3 << " " << Pcard4 << " " << Pcard5 << endl;
						cout << "\t\t\t " << Dhand1 << " " << Dhand2 << " " << Dhand3 << " " << Dhand4 << " " << Dhand5 << "\t\t " << Phand1 << " " << Phand2 << " " << Phand3 << " " << Phand4 << " " << Phand5 << endl;
						cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
						cout << endl;

						if (Dhand >= 17) {

							Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4 + Dhand5;

							WhoWin();
						}
					}
					else if (Dhand >= 17) {

						Dhand = Dhand1 + Dhand2 + Dhand3 + Dhand4;

						WhoWin();
					}
				}
				else if (Dhand >= 17) {

					Dhand = Dhand1 + Dhand2 + Dhand3;

					WhoWin();
				}

			}
			else if (Dhand >= 17) {

				Dhand = Dhand1 + Dhand2;

				WhoWin();

			}
		}

	}
}

//Who is the winner?
void WhoWin() {
	if (Dhand > 21) {
		Dlose = true;
		cout << "\nDealer went bust. You win." << endl;
	}
	else if (Dhand > Phand) {
		Plose = true;
		cout << "\nDealer win." << endl;
	}
	else if (Dhand < Phand) {
		Dlose = true;
		cout << "\nPlayer win." << endl;
	}
	else if (Dhand == Phand) {
		DrawGame = true;
		GameOver = true;
		cout << "\nDraw" << endl;
	}
}

void Play() {

	Dcard1 = cards[0];
	Pcard1 = cards[1];
	Pcard2 = cards[2];
	Dcard2 = cards[3];


	Dhand1 = stoi(cardValues[0]); //convert string to int
	Phand1 = stoi(cardValues[1]);
	Phand2 = stoi(cardValues[2]);
	Dhand2 = stoi(cardValues[3]);

	//Is A 1 or 11? 
	if (Phand1 == 1 && Phand2 <= 10) {
		Phand1 = 11;
	}
	else if (Phand2 == 1 && Phand1 <= 10) {
		Phand2 = 11;
	}

	if (Dhand1 == 1 && Dhand2 <= 10) {
		Dhand1 = 11;
	}
	else if (Dhand2 == 1 && Dhand1 <= 10) {
		Dhand2 = 11;
	}

	//if both hit blackjack game is draw.
	if (((Phand2 == 10 && Phand1 == 11) || (Phand1 == 10 && Phand2 == 11)) && ((Dhand2 == 10 && Dhand1 == 11) || (Dhand1 == 10 && Dhand2 == 11))) {
		DrawGame = true;
		GameOver = true;
	}

	else if ((Phand2 == 10 && Phand1 == 11) || (Phand1 == 10 && Phand2 == 11)) {
		PBlackjack = true;
		GameOver = true;
	}

	else if ((Dhand2 == 10 && Dhand1 == 11) || (Dhand1 == 10 && Dhand2 == 11)) {
		DBlackjack = true;
		GameOver = true;
	}

	

	Phand = Phand1 + Phand2;
	Dhand = Dhand1 + Dhand2;


	cout << endl;
	cout << "\t\t\t Dealer cards" << "\t\t" << " Your cards "  << endl;
	cout <<"\t\t\t " << Dcard1 << " " << Dcard2 << "\t\t\t " << Pcard1 << " " << Pcard2 << endl;
	cout <<"\t\t\t " << Dhand1 << " " << Dhand2 << "\t\t\t " << Phand1 << " " << Phand2 <<endl;
	cout << "\t\t\t " << Dhand << " " << "\t\t\t " << Phand << endl;
	cout << endl;
}

int main() {

	string PName;

	char YorN;
	char HorS;



	cout << "Enter your name here: ";
	cin >> PName;

	
	srand(time(0));


	do
	{
		cout << "\n\t\t\tMR. " << PName << ", WELCOME TO THE BLACKJACK TABLE SIR.\n" << endl;

		cout << "\t\t*****************************************************************" << endl;
		cout << "\t\t*\t\t INFORMATIONS FOR PLAYERS\t\t\t*" << endl;
		cout << "\t\t*                                                               *" << endl;
		cout << "\t\t*\tDealer must take a card if he hits 16 or below.\t\t* " << endl;
		cout << "\t\t*\tDealer must stand at 17 or above.\t\t\t*" << endl;
		cout << "\t\t*\tDealer can only draw 3 cards.\t\t\t\t*" << endl;
		cout << "\t\t*\tPlayer can only hit 4 cards.\t\t\t\t*" << endl;
		cout << "\t\t*\tHit: Take another card.\t\t\t\t\t*" << endl;
		cout << "\t\t*\tStand: Take no more cards.\t\t\t\t*" << endl;
		cout << "\t\t*\tThe dealer shuffles the deck with each new game.\t*" << endl;
		cout << "\t\t*                                                               *" << endl;
		cout << "\t\t*****************************************************************" << endl;


		HitCounter = 0;

		GameOver = false;
		PBlackjack = false;
		DBlackjack = false;
		Dlose = false;
		Plose = false;
		DrawGame = false;



		Shuffle(cards, 52);
		Shuffle(cardValues, 52);

		Play();


		while (GameOver == false) {
			cout << endl;
			cout << "Hit or Stand?(H/S): ";
			cin >> HorS;

			Hit(HorS);
			Stand(HorS);

			if (Plose == true || Dlose == true) {
				break;
			}
		}

		//both hit blackjack
		if (PBlackjack == true && DBlackjack == true) {
			cout << endl;
			cout << "Draw" << endl;
		}
		else if (PBlackjack == true) {
			cout << endl;
			cout << "You hit blackjack. You win." << endl;
		}
		else if(DBlackjack==true){
			cout << endl;
			cout << "Dealer blackjack. Dealer win." << endl;
		}


		cout << endl;
		cout << "Do you want to play again?(Y/N): ";
		cin >> YorN;

		system("cls");

		} while (YorN == 'y' || YorN == 'Y');

		cout << endl;
		cout << "THANKS FOR PLAYING" << endl;

		return 0;
	}