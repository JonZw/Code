#ifndef statistics_HH
#define statistics_HH

#include <vector>

//Giebt die Durchschnitt an
double mean(const std::vector<double>& v);
//Giebt den Median zurück
double median(const std::vector<double>& v);
//Giebt den statistische Moment von k wieder (was auch immer das ist)
double moment(const std::vector<double>& v,int k);
//berechnet die Standardabweichung
double standard_deviation(const std::vector<double>& v);
//s.o.
double standard_deviation2(const std::vector<double>& v);
#endif // IO_HH
