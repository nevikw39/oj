class Solution:
    days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        aam, aad = map(int, arriveAlice.split('-'))
        lam, lad = map(int, leaveAlice.split('-'))
        abm, abd = map(int, arriveBob.split('-'))
        lbm, lbd = map(int, leaveBob.split('-'))
        y = 0
        for i in range(1, 13):
            for j in range(1, 1 + self.days[i]):
                if aam != lam:
                    a = aam == i and aad <= j or aam < i < lam or i == lam and j <= lad
                else:
                    a = i == aam and aad <= j <= lad
                if abm != lbm:
                    b = abm == i and abd <= j or abm < i < lbm or i == lbm and j <= lbd
                else:
                    b = i == abm and abd <= j <= lbd
                y += a and b
        return y

if __name__ == "__main__":
    sln = Solution()
    print(sln.countDaysTogether(arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"))
    print(sln.countDaysTogether(arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"))
    print(sln.countDaysTogether(arriveAlice = "01-31", leaveAlice = "02-01", arriveBob = "01-31", leaveBob = "02-01"))
