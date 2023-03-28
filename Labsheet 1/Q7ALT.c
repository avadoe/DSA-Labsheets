#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 10000

int hashmap[26];
char sentence[MAX_LEN];
char word[26];

int min_window_len = MAX_LEN;
int start_idx, end_idx;

int count_map[26];

int main() {
  scanf("%[^\n]s", sentence);
  scanf("%s", word);

  int len_sentence = strlen(sentence);
  int len_word = strlen(word);

  for (int i = 0; i < len_word; i++) {
    hashmap[word[i] - 'a']++;
  }

  int start = 0, end = 0, count = 0;
  while (end < len_sentence) {
    if (hashmap[sentence[end] - 'a'] > 0) {
      count_map[sentence[end] - 'a']++;
      if (count_map[sentence[end] - 'a'] <= hashmap[sentence[end] - 'a']) {
        count++;
      }
    }

    if (count == len_word) {
      while (hashmap[sentence[start] - 'a'] == 0 ||
             count_map[sentence[start] - 'a'] > hashmap[sentence[start] - 'a']) {
        if (count_map[sentence[start] - 'a'] > hashmap[sentence[start] - 'a']) {
          count_map[sentence[start] - 'a']--;
        }
        start++;
      }

      int window_len = end - start + 1;
      if (window_len < min_window_len) {
        min_window_len = window_len;
        start_idx = start;
        end_idx = end;
      }
    }

    end++;
  }

  if (min_window_len == MAX_LEN) {
    printf("NO WINDOW\n");
  } else {
    printf("%d %d\n", start_idx, end_idx);
    for (int i = start_idx; i <= end_idx; i++) {
      printf("%c", sentence[i]);
    }
    printf("\n");
  }

  return 0;
}