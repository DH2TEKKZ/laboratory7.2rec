#include "pch.h"
#include "CppUnitTest.h"
#include "../laboratory7.2rec/laboratory7.2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 5;
			int colCount = 5;
			int low = -10;
			int high = 10;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			Create(a, rowCount, colCount, low, high, 0, 0);

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::IsTrue(a[i][j] >= low && a[i][j] <= high);
				}
			}
			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
		TEST_METHOD(TestMinElement)
		{
			int arr[3][3] = {
				{ -1, -3, -2 },
				{ -7, -4, -5 },
				{ -8, -6, -9 }
			};
			int* a[3];
			for (int i = 0; i < 3; ++i) {
				a[i] = arr[i];
			}
			int rowCount = 3;
			int colCount = 3;

			int result = minElement(a, rowCount, colCount, 0, 0);

			Assert::AreEqual(-3 + -7 + -9, result);
		}
	};
}
