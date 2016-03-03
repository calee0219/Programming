#include <cstdint>

namespace problem2{

	template<uintmax_t N>
	struct Fib{

		// Change this line
		constexpr static uintmax_t Value = 0;

		static_assert(Fib<N>::Value >= Fib<N-1>::Value,
		              "Overflow!");

    };

	// Fill code here

}
