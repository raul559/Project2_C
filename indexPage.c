/* File: indexPage.c */
/* Author: Britton Wolfe */
/* Date: September 3rd, 2010 */

/* This program indexes a web page, printing out the counts of words on that page */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LOWERCASE_LETTERS 26

typedef struct TrieNode TrieNode;
struct TrieNode
{
  //holds the letter
  char data;
  // array of pointers for children nodes
  struct TrieNode *childNode[LOWERCASE_LETTERS];
  int wordCount;
};
// root node declaration
struct TrieNode *root = NULL;

// returns a new Trie Node
struct TrieNode *createNode()
{
  // memory allocation of new node
  struct TrieNode *node = malloc(sizeof(struct TrieNode));
  node->wordCount = 0;
  node->data = -1;
  // initializing child nodes
  for (int i = 0; i < LOWERCASE_LETTERS; i++)
  {
    node->childNode[i] = NULL;
  }
  return node;
};

/* NOTE: int return values can be used to indicate errors (typically non-zero)
   or success (typically zero return value) */

/* TODO: change this return type */
void indexPage(const char *url);

int addWordOccurrence(const char *word, const int wordLength
                      /* TODO: other parameters you need */);

void printTrieContents(/* TODO: any parameters you need */);

int freeTrieMemory(struct TrieNode *node);

int getText(const char *srcAddr, char *buffer, const int bufSize);

int main(int argc, char **argv)
{
  /* TODO: write the (simple) main function

  /* argv[1] will be the URL to index, if argc > 1 */

  // indexPage();
  // printTrieContents();
  // freeTrieMemory();

  return 0;
}

/* TODO: define the functions corresponding to the above prototypes */

/* TODO: change this return type */
void indexPage(const char *url)
{
}

int addWordOccurrence(const char *word, const int wordLength
                      /* TODO: other parameters you need */)
{
}

void printTrieContents(/* TODO: any parameters you need */)
{
}

int freeTrieMemory(struct TrieNode *node)
{
  for (int i = 0; i < LOWERCASE_LETTERS; i++)
  {
    freeTrieMemory(node->childNode[i]);
  }

  free(node);
}

/* You should not need to modify this function */
int getText(const char *srcAddr, char *buffer, const int bufSize)
{
  FILE *pipe;
  int bytesRead;

  snprintf(buffer, bufSize, "curl -s \"%s\" | python3 getText.py", srcAddr);

  pipe = popen(buffer, "r");
  if (pipe == NULL)
  {
    fprintf(stderr, "ERROR: could not open the pipe for command %s\n",
            buffer);
    return 0;
  }

  bytesRead = fread(buffer, sizeof(char), bufSize - 1, pipe);
  buffer[bytesRead] = '\0';

  pclose(pipe);

  return bytesRead;
}
