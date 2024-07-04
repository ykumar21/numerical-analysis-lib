#ifndef DBSCAN_H
#define DBSCAN_H

#include <vector>

class DBSCAN {
 public:
  DBSCAN(double eps, int minPts);
  std::vector<int> fit(const std::vector<std::vector<double>>& data);

 private:
  double eps_;
  int minPts_;
};

#endif