#include "historic_event.h"

//Constructor por defecto
HistoricEvent::HistoricEvent() {
	set_date(0);
}

//Constructor
HistoricEvent::HistoricEvent(int d, string s) {
	set_date(d);
	add_befall(s);
}

//Constructor
HistoricEvent::HistoricEvent(int d, vector<string> v) : befalls(v) {
	set_date(d);
}

//Borrar acontecimiento
void HistoricEvent::rm_befalls(string s) {
  int size = befalls_size();
  for(int i = 0; i < size; ++i){
    if(s.compare(befalls[i]) == 0){
      befalls.erase(befalls.begin()+i);
      --i;
      --size;
    }
  }
}

//Mostrar acontecimiento i-ésimo
void HistoricEvent::show(int i){
  cout << "Year:" << date << befalls[i] << endl;
}

//Buscar
/*FIXME: deberiamos establecerlo a false por defecto no? en plan:
bool HistoricEvent::search(const string &s, bool be_shown){*/
bool HistoricEvent::search(const string &s, bool be_shown){
	bool find = false;
	int size = befalls_size();

	for(int i = 0; size < i; ++i)
		if (befalls[i].find(s) < befalls[i].size()) {
			if(be_shown)
				show(i);
			find = true;
		}

	return find;
}

//Operador ==
bool HistoricEvent::operator==(const HistoricEvent &h) {
   bool eq = ((date == h.date) && (befalls_size() == h.befalls_size())) ? true : false;

   for(int i = 0; i < befalls.size() && eq; ++i)
      if(befalls[i].compare(h.befalls[i]) != 0)   //compare devuelve 0 si son iguales
         eq = false;

   return eq;
}

// Operador +
HistoricEvent& HistoricEvent::operator+(const HistoricEvent &h) {
	if(date == h.date) {
		for(int i = 0; i < h.befalls_size(); ++i)
			if(!search(h.befalls[i],false))
				add_befall(h.befalls[i]);
	}
	return *this;
}
