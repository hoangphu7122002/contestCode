class TrieNode:
    def __init__(self):
        self.childNode = [None] * 26
        self.wordEnd = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    # Function to insert a key into the Trie
    def insert(self, key):
        currentNode = self.root
        for char in key:
            index = ord(char) - ord('a')
            if not currentNode.childNode[index]:
                currentNode.childNode[index] = TrieNode()
            currentNode = currentNode.childNode[index]
        currentNode.wordEnd = True

    # Function to search for a key in the Trie
    def search(self, key):
        currentNode = self.root
        for char in key:
            index = ord(char) - ord('a')
            if not currentNode.childNode[index]:
                return False
            currentNode = currentNode.childNode[index]
        return currentNode.wordEnd


if __name__ == "__main__":
    trie = Trie()
    inputStrings = ["and", "ant", "do", "geek", "dad", "ball"]

    # Insert each string into the Trie
    for word in inputStrings:
        trie.insert(word)

    searchQueryStrings = ["do", "geek", "bat"]
    # Search for each string and print whether it is found in the Trie
    for query in searchQueryStrings:
        print("Query String:", query)
        if trie.search(query):
            print("The query string is present in the Trie")
        else:
            print("The query string is not present in the Trie")