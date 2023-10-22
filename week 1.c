#ifndef STATS_H
#define STATS_H

void analyze_data(const unsigned char *data, size_t size, int *max, int *min, int *mean, int *median);
void print_statistics(const int max, const int min, const int mean, const int median);

#endif // STATS_H
