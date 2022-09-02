Jakub Pudlo - Programowanie Systemow Czasu Rzeczywistego

Celem projektu bylo zasymulowanie prostego dzialania diody sygnalizujacej (Telltale), ktora moze zostac zamontowana w samochodzie.

Urzadzenie otrzymuje periodyczne dane od 2 wezlow (Node1 i Node2).
Node1 - wysyla stan pracy silnika z okresem 1s - sygnal wysylany do modulu Telltale tylko gdy Node jest aktywny (aktywacja lub dezaktywacja wykonyana jest przez klawiature poprzez wpisanie "1"; zmiana stanu na przeciwny), a sama warotsc ustawiana jest poprzez znak "-" ktory zmienia stan pomiedzy engine=0/1
Node2 - wysyla request do uruchomienia diody 100ms analogicznie aktywacja/dezaktywacja wezla odbywa sie przy pomocy "2", a zmiana sygnalu wysylanego przy pomocy "+"

Tellteles(simulation.c) - ustawia sygnal wychodzacy na 1 gdy obywa wezly nadaja sygnal rowny 1 lub gdy ktorys z wezlow bedzie nieaktywny przez minimum 5 sekund.

Stan wyjsciowy Tellteles jest zapisywany do pliku telltale_result.txt co 50ms.


Sterowanie:
Uruchomienie programu nalezy zbudowac program oraz uruchomic sudo ./telltale_simulation
"1" - aktywacja/dezaktywacja node1
"2" - aktywacja/dezaktywacja node2
"-" - zmiana statusu silnika
"+" - zmiana sygnalu led

"q" - zamyka aplikacje

Diode request: 0 - ostatnia wartosc wyslana do Telltale
Engine status: 0 - ostatnia wartosc wyslana do Telltale

Node 1 disable counter: 0 - licznik ile czasu dany node jest nieaktywny
Node 2 disable counter: 0 - licznik ile czasu dany node jest nieaktywny
