func traverseV(board [][]byte, i int, j int) bool {
	if board[i][j] == '.' {
		return true
	}
	for t := 0; t < 9; t++ {
		if t == i {
			continue
		}
		if board[t][j] == board[i][j] {
			return false
		}
	}
	return true
}

func traverseH(board [][]byte, i int, j int) bool {
	if board[i][j] == '.' {
		return true
	}
	for t := 0; t < 9; t++ {
		if t == j {
			continue
		}
		if board[i][t] == board[i][j] {
			return false
		}
	}
	return true
}

func check3by3(board [][]byte, i int, j int) bool {
	valid := make([]int, 10)
	for t := i; t < i+3; t++ {
		for u := j; u < j+3; u++ {
			if board[t][u] == '.' {
				continue
			}
			num := board[t][u] - '0'
			if valid[num] != 0 {
				return false
			}
			valid[num] = 1
		}
	}
	return true
}

func isValidSudoku(board [][]byte) bool {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if !traverseV(board, i, j) || !traverseH(board, i, j) {
				return false
			}
		}
	}

	for i := 0; i < 9; i += 3 {
		for j := 0; j < 9; j += 3 {
			if !check3by3(board, i, j) {
				return false
			}
		}
	}

	return true
}