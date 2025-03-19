struct __crazt_lambda_name {
	
	int val;
	template<typename T>
	auto operator() (int i)  {
		return 10 + i + val;
	}
};

int main()
{
	int val = 3;	
	auto l = [val](int i) mutable { return 8 + i + ++val ; }

	// auto  l = __crazy_lambda_name{val}

	return l(4);
}
