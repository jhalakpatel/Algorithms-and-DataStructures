/*
 *	search a pattern in a text, 
 *	approach 1: pre-process the pattern using robin karp(create hash) and iterate over the text (O(n)) time to find out the 
 *	the indices where we can match the text. ( need to learn KMP method for doing the same) --> preprocess pattern and match text
 *
 *	approach 2: using Trie data structure, prepocessing text. (given text does not change frequently e.g. a book) and for a given
 *	pattern (o(m)) process the pattern - 
 *		1. Using Standard Trie DataStructure
 *		2. Using Suffix Tree
 */


// Ukonnen's algorithm to implement suffix tree
