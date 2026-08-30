class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        word_set = set(wordList)
        if endWord not in wordList:
            return 0

        begin_set = {beginWord}
        end_set = {endWord}
        visited = {beginWord,endWord}
        length = 1

        while begin_set and end_set:
            
            if len(begin_set) > len(end_set):
                begin_set, end_set = end_set, begin_set

            next_level = set()
            for word in begin_set:
                for i in range(len(word)):
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        next_word = word[:i] + c + word[i + 1:]

                        if next_word in end_set:
                            return length + 1

                        if next_word in word_set and next_word not in visited:
                            visited.add(next_word)
                            next_level.add(next_word)

            begin_set = next_level
            length += 1
        
        return 0