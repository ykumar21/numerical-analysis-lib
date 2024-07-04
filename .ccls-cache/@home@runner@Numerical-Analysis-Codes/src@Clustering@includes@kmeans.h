#ifndef KMEANS_H
#define KMEANS_H

#include <vector>

template <typename T> 
class KMeans {
 public:
  KMeans(int k, int max_iterations);
  std::vector<int> fit(const T& data);
  T get_centroids() const;
 private:
  int k_;
  int max_iterations_;
  T centroids_;
  std::vector<int> labels_;
};

#endif