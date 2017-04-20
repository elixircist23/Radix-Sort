void int_radix_sort(int *lst, int *dst, int n){
  int group = 8;
  int buckets = 1 << group;
  int mask = buckets - 1;
  int cnt[buckets];
  int map[buckets];

  for(int k = 0; k < 32; k += 8){

    memset(cnt, 0, sizeof(cnt));
    memset(map, 0, sizeof(map));

    for(int i = 0; i < n; i++){
      cnt[(lst[i] >> k) & mask]++;
    }

    map[0] = 0;
    for(int i = 1; i < buckets; i++){
      map[i] = map[i - 1] + cnt[i - 1];
    }

    for(int i = 0; i < n; i++){
      dst[map[(lst[i] >> k) & mask]++] = lst[i];
    }

    for(int i = 0; i < n; i++){
      lst[i] = dst[i];
    }
  }
}

void float_radix_sort(float *lst2, float *dst, int n){
  unsigned int group = 8;
  unsigned int buckets = 1 << group;
  unsigned int mask = buckets - 1;
  unsigned int cnt[buckets];
  unsigned int map[buckets];
  unsigned int *lst = (unsigned int*) lst2;

  for(unsigned int k = 0; k < 32; k += 8){

    memset(cnt, 0, sizeof(cnt));
    memset(map, 0, sizeof(map));

    for(unsigned i = 0; i < n; i++){
      cnt[(lst[i] >> k) & mask]++;
    }

    map[0] = 0;
    for(unsigned i = 1; i < buckets; i++){
      map[i] = map[i - 1] + cnt[i - 1];
    }

    for(unsigned i = 0; i < n; i++){
      dst[map[(lst[i] >> k) & mask]++] = lst2[i];
    }

    for(unsigned i = 0; i < n; i++){
      lst2[i] = dst[i];
    }
  }

}

void correct(float *lst, float *dst, int n){
  int neg_index = 0;

  for(int i = n; i > 0; i--){
    if(lst[i] < 0){
      dst[neg_index] = lst[i];
      neg_index++;
    }
  }
  for(int i = 0; i < n; i++){
    if(lst[i] >= 0){
      dst[i + neg_index] = lst[i];

    }
  }

  for(int i = 0; i < n; i++){
    lst[i] = dst[i];
  }
}
