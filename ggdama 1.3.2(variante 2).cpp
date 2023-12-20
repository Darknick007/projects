#include <iostream>
#include <string>

using namespace std;
/*
INDEX:
0=casella vuota = 0
1=dama piccola bianca = b
2=dama piccola nera = n
3=dama doppia bianca= B
4=dama doppia nera= N
5=caselle in cui ci si può muovere = ~







*/
const int righe = 8;                                                       
const int colonne = 8;                                                                            
//visione                                                                                                                                                                                                                                                  
void Visualizza(int Griglia[righe][colonne]);                                                 
//inizializzare                                                                                                                                                                                   
void InizializzaNero(int Griglia[righe][colonne]);                                          
void InizializzaBianco(int Griglia[righe][colonne]);                                                
void InizializzaCaselle(int Griglia[righe][colonne]);                                             
void InizializzaTotale(int Griglia[righe][colonne]);
bool IsDama(int Griglia[righe][colonne],int PedinaSelezionata[2]);
//Gioco 
void Menu();
void TurnoBianco(int Griglia[righe][colonne], int PedinaSelezionata[2]);
void TurnoNero(int Griglia[righe][colonne], int PedinaSelezionata[2]);

void MovimentoPedina(int Griglia[righe][colonne], int PedinaSelezionata[2],bool turnobianco);

void SelezionePedineBianche(int Griglia[righe][colonne], int PedinaSelezionata[2]);

void VisionePedinaSelezionata(int Griglia[righe][colonne], int PedinaSelezionata[2]);

void SelezionePedineNere(int Griglia[righe][colonne], int PedinaSelezionata[2]);
void PromozioneDama(int Griglia[righe][colonne]);
void Rimuovere5(int Griglia[righe][colonne]);
                                     
//main/////////////////
int main(){ 								//lavorato da tutti e 2
	bool Gioco=true;
	int Griglia[righe][colonne];
	char ON_OFF_Programma;
	int PedinaSelezionata[2];
	int Turni = 0;
	InizializzaTotale(Griglia);
	
	
    while (Gioco) {
        if(Turni %2 == 0){
        TurnoBianco(Griglia, PedinaSelezionata);
        }
        else{
        TurnoNero(Griglia, PedinaSelezionata);
        }
        
        Turni++;
        
    }

}
//funzioni//////////////////////



void InizializzaNero(int Griglia[righe][colonne]){ //fatto da marotta
	Griglia[5][0] = 2; Griglia[5][2] = 2; Griglia[5][4] = 2; Griglia[5][6] = 2;
	Griglia[6][1] = 2; Griglia[6][3] = 2; Griglia[6][5] = 2; Griglia[6][7] = 2;
	Griglia[7][0] = 2; Griglia[7][2] = 2; Griglia[7][4] = 2; Griglia[7][6] = 2;
}

void InizializzaBianco(int Griglia[righe][colonne]){ //fatto da marotta
	Griglia[0][1] = 1; Griglia[0][3] = 1; Griglia[0][5] = 1; Griglia[0][7] = 1;
	Griglia[1][0] = 1; Griglia[1][2] = 1; Griglia[1][4] = 1; Griglia[1][6] = 1;
	Griglia[2][1] = 1; Griglia[2][3] = 1; Griglia[2][5] = 1; Griglia[2][7] = 1;
}





void InizializzaCaselle(int Griglia[righe][colonne]){ //fatto da marotta
	for(int i = 0; i<righe; i++){
		for(int c =0; c<colonne; c++){
			Griglia[i][c] = 0;
		}
	}
	}
	
void InizializzaTotale(int Griglia[righe][colonne]){ //fatto da marotta
	 InizializzaCaselle(Griglia);
	 InizializzaNero(Griglia);                                               
	 InizializzaBianco(Griglia);                                                
	
	
}
	
void Visualizza(int Griglia[righe][colonne]){ //fatto da marotta
 for(int i = 0; i<righe; i++){
 	for(int c=0; c<colonne; c++){
     		if(c==0){
            cout<<i+1;
            cout<<"#";
            }
    cout<<"| ";
     if(Griglia[i][c]==1){
    	cout<<"b";
     }
     if(Griglia[i][c]==2){
     	cout<<"n";
     }
     if(Griglia[i][c]==3){
    	cout<<"B";
     }
     if(Griglia[i][c]==4){
    	cout<<"N";
     }
     if(Griglia[i][c]==0){
    	cout<<"0";
     }
     if(Griglia[i][c]==5){
    	cout<<"~";
     }
     cout<<" ";
                    
  }
  cout<<endl;
             if(i==righe-1){
                  
      cout<<"---------------------------------"<<endl;
      cout<<"    1 | 2 | 3 | 4 | 5 | 6 | 7 | 8"<<endl;

}

 }
}

//generali
void PromozioneDama(int Griglia[righe][colonne]){ //fatto da marotta
    
    for (int colonna = 0; colonna < colonne; colonna++) {
        if (Griglia[0][colonna] == 2) {
            
            Griglia[0][colonna] = 4;
            cout << "Promozione: Dama doppia!" << endl;
        }
    }
    for (int colonna = 0; colonna<colonne; colonna++){
    	if (Griglia[7][colonna] == 1){
    		
    		Griglia[7][colonna] = 3;
    		cout<< "Promozione: Dama doppia!" <<endl;
    	}
    }
}

void TurnoBianco(int Griglia[righe][colonne], int PedinaSelezionata[2]) {
	Visualizza(Griglia);
    SelezionePedineBianche(Griglia, PedinaSelezionata);
    
    VisionePedinaSelezionata(Griglia, PedinaSelezionata);
    Visualizza(Griglia);
    MovimentoPedina(Griglia, PedinaSelezionata,true);
    PromozioneDama(Griglia);  
}


void TurnoNero(int Griglia[righe][colonne], int PedinaSelezionata[2]) {
	Visualizza(Griglia);
    SelezionePedineNere(Griglia, PedinaSelezionata);
    
    VisionePedinaSelezionata(Griglia, PedinaSelezionata);
    Visualizza(Griglia);
    MovimentoPedina(Griglia, PedinaSelezionata,false);
    PromozioneDama(Griglia);  
}



void SelezionePedineBianche(int Griglia[righe][colonne], int PedinaSelezionata[2]){ //fatto da bracale
  int riga;
  int colonna;
  do{
  	    cout<<endl;
		cout<<"Inserisci la riga della pedina bianca da selezionare :  "<<endl;
		cin>>riga;
		cout<<"Inserisci la colonna della pedina bianca da selezionare :  "<<endl;
		cin>>colonna;
		PedinaSelezionata[0] = riga-1;
		PedinaSelezionata[1] = colonna-1;
  }while(Griglia[riga-1][colonna-1]!=1 and Griglia[riga-1][colonna-1]!=3 );
  cout<<"selezionato con successo"<<endl;
}

void VisionePedinaSelezionata(int Griglia[righe][colonne], int PedinaSelezionata[2]) { // fatto da marotta
        int colorePedina = Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]];
        if (colorePedina == 3){
        	colorePedina = 1;
        }
        if (colorePedina == 4){
        	colorePedina = 1;
        }

        switch (colorePedina) {
        	//dame bianche
        case 1:
    if (PedinaSelezionata[0] - 1 >= 0) {
        if (PedinaSelezionata[1] - 1 >= 0) {
            if (Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] - 1] == 0) {
                Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] - 1] = 5;
            }
        }

        if (PedinaSelezionata[1] + 1 < colonne) {
            if (Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] + 1] == 0) {
                Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] + 1] = 5;
            }
        }
    }

    // Mossa per le dame normali
    if (!IsDama(Griglia, PedinaSelezionata)) {
        if (PedinaSelezionata[0] + 1 < righe) {
            if (PedinaSelezionata[1] - 1 >= 0) {
                if (Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] - 1] == 0) {
                    Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] - 1] = 5;
                }
            }

            if (PedinaSelezionata[1] + 1 < colonne) {
                if (Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] + 1] == 0) {
                    Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] + 1] = 5;
                }
            }
        }
    }
            	if (PedinaSelezionata[0] + 2 < righe && PedinaSelezionata[1] - 2 >= 0 && Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] - 1] == 2 && Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] - 2] == 0) {
                Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] - 2] = 5;
            }

            if (PedinaSelezionata[0] + 2 < righe && PedinaSelezionata[1] + 2 < colonne && Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] + 1] == 2 && Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] + 2] == 0) {
                Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] + 2] = 5;
            }

    // Mossa per le dame doppie
    if (IsDama(Griglia, PedinaSelezionata)) {
        if (PedinaSelezionata[0] - 2 >= 0 && PedinaSelezionata[1] - 2 >= 0 && Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] - 1] == 2 && Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] - 2] == 0) {
            Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] - 2] = 5;
        }

        if (PedinaSelezionata[0] - 2 >= 0 && PedinaSelezionata[1] + 2 < colonne && Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] + 1] == 2 && Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] + 2] == 0) {
            Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] + 2] = 5;
        }

        if (PedinaSelezionata[0] + 2 < righe && PedinaSelezionata[1] - 2 >= 0 && Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] - 1] == 2 && Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] - 2] == 0) {
            Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] - 2] = 5;
        }

        if (PedinaSelezionata[0] + 2 < righe && PedinaSelezionata[1] + 2 < colonne && Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] + 1] == 2 && Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] + 2] == 0) {
            Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] + 2] = 5;
        }
    }

    break;
    //dame nere
        case 2:
    if (PedinaSelezionata[0] - 1 >= 0) {
        if (PedinaSelezionata[1] - 1 >= 0) {
            if (Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] - 1] == 0) {
                Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] - 1] = 5;
            }
        }

        if (PedinaSelezionata[1] + 1 < colonne) {
            if (Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] + 1] == 0) {
                Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] + 1] = 5;
            }
        }
    }

    // Mossa per le dame normali
    if (!IsDama(Griglia, PedinaSelezionata)) {
        if (PedinaSelezionata[0] + 1 < righe) {
            if (PedinaSelezionata[1] - 1 >= 0) {
                if (Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] - 1] == 0) {
                    Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] - 1] = 5;
                }
            }

            if (PedinaSelezionata[1] + 1 < colonne) {
                if (Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] + 1] == 0) {
                    Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] + 1] = 5;
                }
            }
        }
 if (PedinaSelezionata[0] - 2 >= 0 && PedinaSelezionata[1] - 2 >= 0 && Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] - 1] == 1 && Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] - 2] == 0) {
    Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] - 2] = 5;
}

if (PedinaSelezionata[0] - 2 >= 0 && PedinaSelezionata[1] + 2 < colonne && Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] + 1] == 1 && Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] + 2] == 0) {
    Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] + 2] = 5;
}
    }
    
    // Mossa per le dame doppie
    if (IsDama(Griglia, PedinaSelezionata)) {
        if (PedinaSelezionata[0] - 2 >= 0 && PedinaSelezionata[1] - 2 >= 0 && Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] - 1] == 1 && Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] - 2] == 0) {
            Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] - 2] = 5;
        }

        if (PedinaSelezionata[0] - 2 >= 0 && PedinaSelezionata[1] + 2 < colonne && Griglia[PedinaSelezionata[0] - 1][PedinaSelezionata[1] + 1] == 1 && Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] + 2] == 0) {
            Griglia[PedinaSelezionata[0] - 2][PedinaSelezionata[1] + 2] = 5;
        }

        if (PedinaSelezionata[0] + 2 < righe && PedinaSelezionata[1] - 2 >= 0 && Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] - 1] == 1 && Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] - 2] == 0) {
            Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] - 2] = 5;
        }

        if (PedinaSelezionata[0] + 2 < righe && PedinaSelezionata[1] + 2 < colonne && Griglia[PedinaSelezionata[0] + 1][PedinaSelezionata[1] + 1] == 1 && Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] + 2] == 0) {
            Griglia[PedinaSelezionata[0] + 2][PedinaSelezionata[1] + 2] = 5;
        }
    }
    break;
        }
    }


bool IsDama(int Griglia[righe][colonne], int PedinaSelezionata[2]) {  //fatto da marotta
    return Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] == 3 || Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] == 4;
}

void SelezionePedineNere(int Griglia[righe][colonne], int PedinaSelezionata[2]){ //fatto da bracale
  int riga;
  int colonna;
  do{
  	    cout<<endl;
		cout<<"Inserisci la riga della pedina nera da selezionare :  "<<endl;
		cin>>riga;
		cout<<"Inserisci la colonna della pedina nera da selezionare :  "<<endl;
		cin>>colonna;
		PedinaSelezionata[0] = riga-1;
		PedinaSelezionata[1] = colonna-1;
  }while(Griglia[riga-1][colonna-1]!=2 and Griglia[riga-1][colonna-1]!=4 );
  cout<<"selezionato con successo"<<endl;
}

//////////////////////////////////////////

void MovimentoPedina(int Griglia[righe][colonne], int PedinaSelezionata[2],bool turnobianco){ //Bracalele
	int NuovaRiga, NuovaColonna, selezione;
	do{
		cout<<" Inserisci la posizione della riga in cui vuoi che la pedina si muova o digitare 0 per tornare alla selezione ";
		cin>>NuovaRiga;
		
        if(turnobianco and NuovaRiga == 0)	{
        	Rimuovere5(Griglia);
        	SelezionePedineBianche(Griglia, PedinaSelezionata);
        	Visualizza(Griglia);
        	VisionePedinaSelezionata(Griglia, PedinaSelezionata);
        	Visualizza(Griglia);
        }
		if(!turnobianco and NuovaRiga ==0){
			Rimuovere5(Griglia);
			SelezionePedineNere(Griglia, PedinaSelezionata);
			Visualizza(Griglia);
			VisionePedinaSelezionata(Griglia, PedinaSelezionata);
			Visualizza(Griglia);
		}	
		
		
		
		
		cout<<" Inserisci la posizione della colonna in cui vuoi che la pedina si muova o digitare 0 per tornare alla selezione  ";
		cin>>NuovaColonna;
		 if(turnobianco and NuovaColonna == 0)	{
		 	Rimuovere5(Griglia);
        	SelezionePedineBianche(Griglia, PedinaSelezionata);
        	Visualizza(Griglia);
        	VisionePedinaSelezionata(Griglia, PedinaSelezionata);
			Visualizza(Griglia);
			
        }
		if(!turnobianco and NuovaColonna ==0){
		    Rimuovere5(Griglia);
			SelezionePedineNere(Griglia, PedinaSelezionata);
			Visualizza(Griglia);
			VisionePedinaSelezionata(Griglia, PedinaSelezionata);
			Visualizza(Griglia);
			//rimuovere 5
		}	
		
		
		
	}while(Griglia[NuovaRiga-1][NuovaColonna-1] != 5 );
	
	if(Griglia[NuovaRiga-1][NuovaColonna-1] == 2 && Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] == 1 or Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] == 3){ //Mangiare nel turno bianco
		Griglia[NuovaRiga][NuovaColonna] = Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]];
		Griglia[NuovaRiga-1][NuovaColonna-1] = 0;
		Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] = 0;
		for(int i = 0; i<righe; i++){
			for(int c =0; c<colonne; c++){
				if(Griglia[i][c] == 5){
					Griglia[i][c] = 0;
				}
			}
		} 

	}
	else if(Griglia[NuovaRiga-1][NuovaColonna-1] == 1 && Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] == 2 or Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] == 4){ //Mangiare nel turno nero
		Griglia[NuovaRiga][NuovaColonna] = Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]];
		Griglia[NuovaRiga-1][NuovaColonna-1] = 0;
		Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] = 0;
		for(int i = 0; i<righe; i++){
			for(int c =0; c<colonne; c++){
				if(Griglia[i][c] == 5){
					Griglia[i][c] = 0;
				}
			}
		} 

	}
	else{
	
	Griglia[NuovaRiga-1][NuovaColonna-1] = Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]];
	Griglia[PedinaSelezionata[0]][PedinaSelezionata[1]] = 0;
		for(int i = 0; i<righe; i++){
		for(int c =0; c<colonne; c++){
			if(Griglia[i][c] == 5){
				Griglia[i][c] = 0;
			}
		}
		} 
	}
}
void Rimuovere5(int Griglia[righe][colonne]){ //da marotta
	for(int i = 0; i<righe; i++){
		for(int c =0; c<colonne; c++){
			if(Griglia[i][c]==5){
		    Griglia[i][c] = 0;
		}
		}
	}
	}	
	
	
	


