int giocataPre = 0;
int turno = 0;
int meta = 0;
bool turnoStart = true;
bool turno1 = true;
bool attendi = true;
int somma = 0;
void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
}
void loop() {
	// put your main code here, to run repeatedly:
  definisciMeta();
	nuovaGiocata();
  winOrLose();
}
void nuovaGiocata()
{

   if(turno == 0)
   {
     
      Serial.println("Scegli il numero: 0, 1, 2, 3, 4, 5, 6");
      attesa();
      caso0(Serial.parseInt());
   }
   else if(turno == 1 || turno == -1)
   {
    if(giocataPre == 0)
    {
    Serial.println("Scegli i numeri: 1, 2, 3, 4, 5, 6");
    attesa();
    caso4(Serial.parseInt());
    }
    if(giocataPre == 1 || giocataPre == 6)
    {
      Serial.println("Scegli il numero: 2, 3, 4, 5");
      attesa();
      caso1(Serial.parseInt());
    }
    if(giocataPre == 2 || giocataPre == 5)
    {
      Serial.println("Scegli il numero: 1, 3, 4, 6");
      attesa();
      caso2(Serial.parseInt());
    }
    if(giocataPre == 3 || giocataPre == 4)
    {
      Serial.println("Scegli il numero: 1, 2, 5, 6");
      attesa();
      caso3(Serial.parseInt());
    }
   }
}

void definisciMeta()
{
  if(turnoStart){
      Serial.println("Inserisci meta");
      attesa();
      meta = Serial.parseInt();
      Serial.println(meta);
      turnoStart = false;  
      }
}
void caso4(int giocata)
{
    giocataPre = giocata;
    somma += giocata;
    turno = -1;
    Serial.println(giocata);
    Serial.println("Punteggio raggiunto: ");
    Serial.println(somma);
}
void caso0(int giocata)
{ 
      if(giocata == 0)
      {
        turno = -1;
        Serial.println(giocata);
        Serial.println("Gioca il secondo giocatore");
      }
      else
      {
        giocataPre = giocata;
        somma += giocata;
        turno = -1;
        Serial.println(giocata);
        Serial.println("Punteggio raggiunto: ");
        Serial.println(somma);
      }

}
void caso1(int giocata)
{
      if(giocata == 1 || giocata == 6 || giocata == 0 && giocata > 6)
      { Serial.println("Non barare");attesa() ;} 
      else
      {
        somma += giocata;
        giocataPre = giocata;
        Serial.println(giocata);
        Serial.println("Punteggio raggiunto: ");
        Serial.println(somma);
        switchTurno();   
      }
      
}
void caso2(int giocata)
{     
      if((giocata == 2 || giocata == 5 || giocata == 0)&& giocata > 6)
      { Serial.println("Non barare");attesa();} 
      else
      {
        somma += giocata;
        giocataPre = giocata;
        Serial.println(giocata);
        Serial.println("Punteggio raggiunto: ");
        Serial.println(somma);
        switchTurno();
      }  
}
void caso3(int giocata)
{
      if((giocata == 3 || giocata == 4 || giocata == 0)&& giocata > 6)
      { Serial.println("Non barare");attesa();} 
      else
      {
        somma += giocata;
        giocataPre = giocata;
        Serial.println(giocata);
        Serial.println("Punteggio raggiunto: "); 
        Serial.println(somma);
        switchTurno();
      }
}
void switchTurno()
{
    if(turno == -1)
    {turno = 1;Serial.println("Gioca il primo");}
    else if(turno == 1)
    {turno = -1;Serial.println("Gioca il secondo");}
}
void attesa()
{
  while(Serial.available() == 0){}
}
void winOrLose()
{
  if((somma == meta && turno == 1) || (somma >= meta && turno == 1))
  {
    Serial.println("Ha vinto il primo giocatore!");ricomincia();
    ricomincia();
  }
  else if((somma == meta && turno == -1) || (somma >= meta && turno == -1))
  {
    Serial.println("Ha vinto il secondo giocatore!");ricomincia();
  }
}  
void ricomincia()
{
  Serial.println("Per ricominciare premere *s*");
  attesa();
  String s = Serial.readString();
  if(s == "s")
  {
    Serial.println("Punteggio riavviato");
    turno = 0;
    somma = 0;
    meta = 0;
    turnoStart = true;
  }
}
