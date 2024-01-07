#include <iostream>
#include <vector>
#include <string>
using namespace std;

class persona {
private:
	int id;
	int password;
	string nome;
	int saldo;
	bool admin;
public:
	//costruttore;
	persona(int personaId, string personanome,int passwordpersona,int saldopersona,bool permessi) {
		id = personaId;
		nome = personanome;
		password = passwordpersona;
		saldo = saldopersona;
		admin = permessi;


	}
	//funzioni
	void display() {
		cout << " id: " << id << endl << " nome: " << nome<<endl << " pass: " << password<<endl << " saldo: " << saldo << endl;

	}
	void deposit(int amount) {
		saldo += amount;
		cout << "deposito effettuato con successo, nuovo saldo: " << saldo << endl;

	}
	void withdraw(int amount) {
		saldo -= amount;
		cout << "ritiro effettuato con successo, nuovo saldo: " << saldo << endl;


	}
	int accessopassword() {
		return password;
	}
	int accessosaldo() {
		return saldo;
	}
	bool accessopermessi() {
		return admin;
	}
};

void inserirepersona(vector<persona>& persone);
bool accesso(vector<persona>& persone,int id);
void deposito(vector<persona>& persone,int id);
void ritiro(vector<persona>& persone, int id);
void lista(vector<persona> persone);

int main() {
	vector<persona> persone;
	int scelta = 0;
	int idpersona;
	int scelta2 = 0;
	int scelta3 = 0;
	bool flag;
	int personamodificare;
	//risparmio di memoria rispetto a un int
	size_t lunghezza = persone.size();
	persona admin(1, "admin", 9999, 0,true);
	persone.push_back(admin);



	//menu
	do {
		
		cout << endl;
		cout << "0-uscire" << endl;
		cout << "1-inserire utente" << endl;
		cout << "2-entrare nel profilo utente" << endl;
		cin >> scelta;
		switch (scelta)
		{
		case 1:
			inserirepersona(persone);
			lunghezza += 1;
			break;
		case 2:
			do {
				cout << "inserire id" << endl;
				cin >> idpersona;
			} while (idpersona > lunghezza+1 or idpersona < 0);
			flag = accesso(persone, idpersona);
			if (flag == false) {
				break;
			}
			if (flag == true and persone[idpersona-1].accessopermessi() != true) {


				//inizio secondo switch
				do {
					cout << "0 per uscire" << endl;
					cout << "1 per informazioni" << endl;
					cout << "2 per depositare" << endl;
					cout << "3 per ritirare" << endl;
						cin >> scelta2;
						switch(scelta2)
						{
						case 1:
							persone[idpersona-1].display();
							break;
						case 2:
							deposito(persone,idpersona);
							break;
						case 3:
							ritiro(persone, idpersona);
							break;
								
						default:
							break;
						}









				} while (scelta2 != 0);  //fine secondo switch
				break;





			
			}//fine if switch


			if (flag == true and persone[idpersona - 1].accessopermessi() == true) {

				
				//inizio secondo switch
				do {
					cout << "0 per uscire" << endl;
					cout << "1 per informazioni" << endl;
					cout << "2 per deposito" << endl;
					cout << "3 per ritirare" << endl;
					cout << "4 per lista account" << endl;
					cout << "5 modificare specifico account" << endl;


					cin >> scelta2;
					switch (scelta2)
					{
					case 1:
						persone[idpersona - 1].display();
						break;
					case 2:
						deposito(persone, idpersona);
						break;
					case 3:
						ritiro(persone, idpersona);
						break;
					case 4:
						lista(persone);
						break;
					case 5:
						do {
							cout << "id persona modificare: ";
							cin >> personamodificare;
						} while (personamodificare < 1 or personamodificare > persone.size());
						if (personamodificare == 0) {
							break;
						}
						//switch3
						do {
							cout << "0 per uscire" << endl;
							cout << "1 per rimuovere soldi" << endl;
							cout << "2 per aggiungere soldi" << endl;
							cin >> scelta3;
							switch (scelta3) {
								
							case 1:
								ritiro(persone, personamodificare);
								break;
							case 2:
								deposito(persone, personamodificare);
							    break;



							default:
								break;

							}




						} while (scelta3 != 0);
						












                        //////////////////

						break;
					default:
						break;
					}









				} while (scelta2 != 0);  //fine secondo switch
				break;
			}
			



		default:
			break;
		}







	} while (scelta != 0);
	
	
	








}




void lista(vector<persona> persone) {
	size_t lunghezza = persone.size();
	for (int i = 0; i < lunghezza;i++) {
		persone[i].display();



	}




}


void ritiro(vector<persona>& persone, int id) {
	int cifraritiro;
	do {
		cout << "cifra da ritirare: " << endl;
		cin >> cifraritiro;
	} while (cifraritiro > persone[id-1].accessosaldo());
	persone[id - 1].withdraw(cifraritiro);
}










void deposito(vector<persona>& persone,int id) {
	int cifradeposito;
	do {
		cout << "cifra da depositare: " << endl;
		cin >> cifradeposito;
	} while (cifradeposito < 0);
	persone[id-1].deposit(cifradeposito);
}











bool accesso(vector<persona>& persone, int id) {
	int tentativopassword;

	do {
		cout << "inserire password (0 per uscire): ";
		cin >> tentativopassword;

		if (tentativopassword == 0) {
			cout << "uscita dal processo di accesso " << endl;
			return false;
		}

		if (tentativopassword != persone[id-1].accessopassword()) {
			cout << "password errata " << endl;
		}
		else {
			cout << "accesso effettuato con successo " << endl;
			return true;
		}
	} while (tentativopassword != 0);
}





void inserirepersona(vector<persona>& persone) { //puntatore & persone così che viene modificato il vettore in caso contrario sarebbe data una copia del vettore e non è quello che noi vogliamo!
	string nomepersonainserire;
	int passworddainserire;
	
    //*
		cout << "inserire nome " << endl;
		cin >> nomepersonainserire;


	do {
		cout << "inserire password di 4 numeri " << endl;
		cin >> passworddainserire;

	} while (passworddainserire < 1000 or passworddainserire>9999);

	//inizializzazione
	persona nuovapersona(persone.size() + 1, nomepersonainserire + to_string(persone.size() + 1),passworddainserire,0,false); //primo elemento id ovvero numero della persona nel vector, secondo elemento il nome della persona insieme al numero per evitare nomi doppioni
	persone.push_back(nuovapersona);
	nuovapersona.display();


};