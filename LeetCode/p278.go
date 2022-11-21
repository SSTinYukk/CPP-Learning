package leetcode

/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */
// func isBadVersion(version int) bool
// func firstBadVersion(n int) int {
// 	left, right := 0, n
// 	var mid int
// 	var res bool
// 	for left <= right {
// 		mid = (left + right) / 2
// 		res = isBadVersion(mid)
// 		if !res {
// 			left = mid + 1
// 		} else {
// 			right = mid - 1
// 		}
// 	}
// 	return left
// }
