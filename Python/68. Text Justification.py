class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        result = []
        line = []
        line_length = 0
        
        for word in words:
            if line_length + len(line) + len(word) <= maxWidth:
                line.append(word)
                line_length += len(word)
            else:
                spaces_to_insert = maxWidth - line_length
                if len(line) == 1:
                    result.append(line[0] + ' ' * spaces_to_insert)
                else:
                    spaces_between_words = spaces_to_insert // (len(line) - 1)
                    extra_spaces = spaces_to_insert % (len(line) - 1)
                    formatted_line = line[0]
                    for i in range(1, len(line)):
                        formatted_line += ' ' * (spaces_between_words + (1 if i <= extra_spaces else 0)) + line[i]
                    result.append(formatted_line)
                
                line = [word]
                line_length = len(word)
        
        last_line = ' '.join(line)
        last_line += ' ' * (maxWidth - len(last_line))
        result.append(last_line)
        
        return result