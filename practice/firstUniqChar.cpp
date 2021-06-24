int firstUniqChar(string s) {
	// 1. 统计每个字符出现的次数
	int count[256] = { 0 };
	for (auto e : s)
		count[e]++;

	// 2. 找第一个出现1次的
	for (int i = 0; i < 256; ++i)
	{
		if (count[i] == 1)
			return i;
	}

	return -1;
}
