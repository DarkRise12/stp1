#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab8_ComplexEditor/TEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(TEditorTest) {
public:
	TEST_METHOD(Init_And_Output_1) {
		TEditor testClass;
		string output = "10,3+i*0,8";
		testClass.writeNumber(output);
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_2) {
		TEditor testClass;
		string output = "-12,6-i*66,2";
		testClass.writeNumber(output);
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_3) {
		TEditor testClass;
		string output = "0,3+i*0,0";
		testClass.writeNumber(output);
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_4) {
		TEditor testClass;
		testClass.writeNumber("aaaaaaaaa");
		string output = "0,+i*0,";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_5) {
		TEditor testClass;
		testClass.writeNumber("66+i*66");
		string output = "0,+i*0,";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_6) {
		TEditor testClass;
		string output = "123,123-i*123,";
		testClass.writeNumber(output);
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_7) {
		TEditor testClass;
		testClass.writeNumber("44,44+44,44*i");
		string output = "0,+i*0,";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_8) {
		TEditor testClass;
		testClass.writeNumber("15,6+g*15,6");
		string output = "0,+i*0,";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_9) {
		TEditor testClass;
		testClass.writeNumber("-9992D,DDDD");
		string output = "0,+i*0,";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(Init_And_Output_10) {
		TEditor testClass;
		testClass.writeNumber("1111+i*1111");
		string output = "0,+i*0,";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(IsZero_1) {
		TEditor testClass;
		testClass.writeNumber("12,36+i*12,35");
		Assert::AreEqual(false, testClass.isZero());
	}
	TEST_METHOD(IsZero_2) {
		TEditor testClass;
		testClass.writeNumber("test");
		Assert::AreEqual(true, testClass.isZero());
	}
	TEST_METHOD(ToggleMinus_1) {
		TEditor testClass;
		testClass.writeNumber("12,36+i*12,35");
		testClass.toggleMinus();
		string output = "-12,36+i*12,35";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(ToggleMinus_2) {
		TEditor testClass;
		testClass.writeNumber("-12,36+i*12,35");
		testClass.toggleMinus();
		string output = "12,36+i*12,35";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(ToggleMinus_3) {
		TEditor testClass;
		testClass.writeNumber("-12,36+i*12,35");
		testClass.toggleMode();
		testClass.toggleMinus();
		string output = "-12,36-i*12,35";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(ToggleMinus_4) {
		TEditor testClass;
		testClass.writeNumber("-12,36-i*12,35");
		testClass.toggleMode();
		testClass.toggleMinus();
		string output = "-12,36+i*12,35";
		Assert::AreEqual(output, testClass.readNumber());
	}
	/*
	TEST_METHOD(AddNumber_1) {
		TEditor testClass;
		testClass.writeNumber("-3,4");
		testClass.addNumber(4);
		string output = "-34,4";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(AddNumber_2) {
		TEditor testClass;
		testClass.writeNumber("0,44");
		testClass.addNumber(4);
		string output = "4,44";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(AddNumber_3) {
		TEditor testClass;
		testClass.writeNumber("42,3");
		testClass.toggleMode();
		testClass.addNumber(4);
		string output = "42,34";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(AddNumber_4) {
		TEditor testClass;
		testClass.writeNumber("42,3");
		testClass.toggleMode();
		testClass.addNumber(0);
		string output = "42,30";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(DelNumber_1) {
		TEditor testClass;
		testClass.writeNumber("42,3");
		testClass.delNumber();
		string output = "4,3";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(DelNumber_2) {
		TEditor testClass;
		testClass.writeNumber("0,3");
		testClass.delNumber();
		string output = "0,3";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(DelNumber_3) {
		TEditor testClass;
		testClass.writeNumber("2,3");
		testClass.delNumber();
		string output = "0,3";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(DelNumber_4) {
		TEditor testClass;
		testClass.writeNumber("42,3");
		testClass.toggleMode();
		testClass.delNumber();
		string output = "42,1";
		Assert::AreEqual(output, testClass.readNumber());
	}
	TEST_METHOD(DelNumber_5) {
		TEditor testClass;
		testClass.writeNumber("42,33");
		testClass.toggleMode();
		testClass.delNumber();
		string output = "42,3";
		Assert::AreEqual(output, testClass.readNumber());
	}*/
	TEST_METHOD(Clear) {
		TEditor testClass;
		testClass.writeNumber("12,34+i*12,34");
		testClass.clear();
		string output = "0,+i*0,";
		Assert::AreEqual(output, testClass.readNumber());
	}

	};
}