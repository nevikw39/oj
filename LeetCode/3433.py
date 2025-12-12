from typing import List


class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        mentions = [0] * numberOfUsers
        offlines = [-60] * numberOfUsers
        for evt_type, timestamp, content in sorted(map(lambda x: (x[0][0] == 'M', int(x[1]), x[2]), events), key=lambda x: (x[1], x[0])):
            if evt_type:
                for i in content.split():
                    match i:
                        case "ALL":
                            mentions[:] = (user + 1 for user in mentions)
                        case "HERE":
                            mentions[:] = (user + (offline + 60 <= timestamp) for user, offline in zip(mentions, offlines))
                        case _ if i.startswith("id"):
                            mentions[int(i[2:])] += 1
            else:
                offlines[int(content)] = timestamp
        return mentions


if __name__ == "__main__":
    sln = Solution()
    assert sln.countMentions(2, [["MESSAGE", "10", "id1 id0"], ["OFFLINE", "11", "0"], ["MESSAGE", "71", "HERE"]]) == [2, 2]
    assert sln.countMentions(2, [["MESSAGE", "10", "id1 id0"], ["OFFLINE", "11", "0"], ["MESSAGE", "12", "ALL"]]) == [2, 2]
    assert sln.countMentions(2, [["OFFLINE", "10", "0"], ["MESSAGE", "12", "HERE"]]) == [0, 1]
    assert sln.countMentions(3, [["MESSAGE", "2", "HERE"], ["OFFLINE", "2", "1"], ["OFFLINE", "1", "0"], ["MESSAGE", "61", "HERE"]]) == [1, 0, 2]
