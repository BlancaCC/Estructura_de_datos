#include "chronology.h"

//Constructor por defecto

//Ordenar por fecha

//Eventos anteriores

//Eventos posteriores


void Chronology::InsertBefall(int date,string s){
  bool insert = false;
  int var_date;
  for(int i=0; insert == false; i++){
    var_date = event.at(i).get_date();
    if (var_date > date){
      HistoricEvent event(date,string);
      event.insert(i,event);
      insert = true;
    }
    else if (var_date == date){
      event.at(i).add_befall(s);
      insert = true;
    }
  }
}


Chronology::rm_event (int a)  {
	int i = 0;
	while (a != events[i].get_date()) {				//compare vale 0 si son iguales
		i++;
	}

	events.erase(i);
}
