// NOTE yo tampoco sé donde poner lo de autores si justo aquí o en la descripción de la clase
/**
  * @file historic_event.h
  * @brief Fichero cabecera del TDA HistoricEvent
  *
  */

#ifndef __CHRONOLOGY
#define __CHRONOLOGY

#include "historic_event.h"

/**
  *  @brief T.D.A. Chronology
  *
  * Una instancia @e h del tipo de datos abstracto @c Chronology se compone
  * de un conjunto de eventos históricos. Se representara un vector de eventos
  * históricos. Ver documentación de historic_event para más información.
  *
  	TODO (si sobra tiempo)
  * Un ejemplo de su uso:
  * @include
  */

class Chronology {

 private: // TODO
/**
  * @page repConjunto Rep del TDA Chronology
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Chronology representa
  *
  *
  *
*/
	vector<Chronology> event; /**< vector con los eventos historicos */

 public:
/**
  * @brief Constructor por defecto de la clase.
  */
  Chronology();

/**
  * @brief Eventos
  * @return Devuelve un vector de eventos
  */
  vector<HistoricEvent> get_events() const {return event;};

/** @brief Inserta un evento en su posición correspondiente
  * @param s Nombre del evento
  * @param date Fecha del evento
  * @return void
  */
  void InsertBefall(int date, string s);

/**
  * @brief Ordenar por fecha
  * @return Cronología ordenada  //NOTE ¿void?
  */
  Chronology& sort();

/**
  * @brief Eventos anteriores
  * @param d año a partir del cual se buscan los eventos
  * @return Vector con los eventos correspondientes
  */
  vector<HistoricEvent> prev_events(unsigned int d);

/**
  * @brief Eventos posteriores
  * @param d año a partir del cual se buscan los eventos
  * @return Vector con los eventos correspondientes
  */
  vector<HistoricEvent> post_events(unsigned int d);

/**
  * @brief Eventos posteriores
  * @param d año a partir del cual se buscan los eventos
  * @return Vector con los eventos correspondientes
  */
  void rm_event (int i);
};

#endif
