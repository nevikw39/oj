class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        lst = []
        for i in range(rows):
            lst.append(encodedText[i * len(encodedText) //
                                   rows: (i + 1) * len(encodedText) // rows])
        y = ""
        for i in range(len(encodedText) // rows):
            for j in range(rows):
                if i + j >= len(encodedText) // rows:
                    break
                y += lst[j][i + j]
        return y.rstrip()


if __name__ == "__main__":
    sln = Solution()
    print(sln.decodeCiphertext("ch   ie   pr", 3))
    print(sln.decodeCiphertext("iveo    eed   l te   olc", 4))
    print(sln.decodeCiphertext("coding", 1))
    print(sln.decodeCiphertext(" b  ac", 2))
