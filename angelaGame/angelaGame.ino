#include <LiquidCrystal.h>
int turnoGioco = 0;
int numeroSceltoPre = 0;
int punteggioScelto = 0;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  if(turnoGioco == 0)
  {
    int contenitore[] = {0,1,2,3,4,5,6};
    numeroSceltoPre = contenitore[Serial.parseInt()]; // definire Posizione basata su input utente 
    Serial.println("Scegli un numero");
    if(numeroSceltoPre == 0)
    {
      turnoGioco == -1;
    }
    else
    {
      punteggioScelto -= numeroSceltoPre;
    }
  }
  if(turnoGioco == -1)
  {
      Selezione(Serial.parseInt()); // definire Posizione da Utente       
  }
  if(turnoGioco == 1)
  {
      Selezione(Serial.parseInt()); // definire Posizione da Utente
  }
    
  }

void Selezione(int posizione)
{
if(numeroSceltoPre == 1 || numeroSceltoPre == 6)
      {
        int contenitore[] ={2,3,4,5};
        numeroSceltoPre = contenitore[posizione-2];
      }
      if(numeroSceltoPre == 2 || numeroSceltoPre == 5)
      {
        int contenitore[] ={1,3,4,6};
        numeroSceltoPre = contenitore[posizione];
      }
      if(numeroSceltoPre == 3 || numeroSceltoPre == 4)
      {
        int contenitore[] ={1,2,5,6};
        numeroSceltoPre = contenitore[posizione]; 
      }
}


