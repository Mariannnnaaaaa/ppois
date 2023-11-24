#include "pch.h"
#include "CppUnitTest.h"
#include "../University.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentInformationSystemTest
{
	TEST_CLASS(StudentInformationSystemTest)
	{
	public:
		
		TEST_METHOD(Input_student)
		{
			Student student1;
			student1.setCourse("final");
			student1.setSpeciality("AI");
			student1.setName("Daria");
			student1.setSurname("Shmyg");
			student1.addInformation("I am very responsible person");
			student1.addSkill("Drawing in photoshop");
			student1.addLink("https://yandex.by/images/search?from=tabbar&text=%D0%B5%D0%B6%D0%B8%D0%BA");
			Grade grade1;
			grade1.setGrade(7);
			grade1.setDate("20/06");
			Course course1;
			course1.setCourseName("PPOIS");
			course1.setDescription("Software design in intelligent systems 2023");
			grade1.setCourse(course1);
			student1.addGrade(grade1);
			Student student2("Marianna", "Yurkevich", "AI");
			Teacher teacher1;
			Teacher teacher2("Irina", "Alegrova", "Professor");
			Book book1("AI in the real life","Job Kakoita","21/12/2012",345);
			Certificate certificate1("reference", "03/04/2023", "08/04/2023", "a respectful reason");
			student1.viewMissedClasses();
			student2.orderStatement();
			student1.calculateAverageGrade();
			student1.orderBook("Drawing in AI", "Maybe Kendall", "18/04/2002", 234);
			student2.viewSchedule();
			student1.viewGrades();
			student1.applyForDiplomaProject();
			Lesson lesson1("12:25","Friday","414-5","lecture");
			student1.attendLesson(lesson1);
			student2.isPresentAtLesson(lesson1);
			Student student3;
			student3.applyForAccommodation();
			student3.applyForSickLeave();
			student3.orderCertificate("reference", "23/01/2023", "02/02/2023", "a respectful reason");
			student3.viewCertificateHistory();
			University BSUIR;
			BSUIR.viewStudentsInfo();
			BSUIR.viewStudentRank(student1);
			Schedule schedule1;
			student1.addFavoriteSchedule(schedule1);
			student1.enrollCourse(course1);
			student1.getFavoriteSchedules();
			student1.getLinks();
			student1.getCourse();
			student1.getDocuments();
			student1.getSkills();
			student1.getSpeciality();
			student1.getName();
			student1.getStudentID();
			Assert::AreEqual(book1.getPageCount(), 345);
		}
		TEST_METHOD(Input_teacher)
		{
			Teacher teacher1;
			teacher1.setName("Nikolai");
			teacher1.setSurname("Ivanov");
			teacher1.setPosition("laboratory assistant");
			Course course1;
			course1.setDescription("TMOIS");
			teacher1.addCourse(course1);
			teacher1.addLesson("9:00", "Monday", "607-5", "laboratory work");
			teacher1.addComment(0, "Be all!!!");
			Lesson lesson1("10:35", "Tuesday", "106-4", "lecture");
			Teacher teacher2;
			teacher2.checkAttendance(lesson1);
			Student student1;
			teacher1.gradeStudent(student1, course1, 8, "12/12/2023");
			teacher2.markAsMissed(0);
			teacher2.editLesson(0, "14:00", "Wednesday", "201-5", "practice work");
			string str = "Tuesday";
			University BSUIR;
			BSUIR.viewTeachersInfo();
			Assert::AreEqual(lesson1.getDayOfWeek(), str);
		}
		TEST_METHOD(Input_certificate)
		{
			Certificate certificate1;
			certificate1.setDocumentType("reference");
			certificate1.setStartDate("04/05/2023");
			certificate1.setEndDate("11/05/2023");
			certificate1.setNotes("concert");
			string str = "concert";
			Assert::AreEqual(certificate1.getNotes(), str);
		}
		TEST_METHOD(Input_book)
		{
			Book book1;
			book1.setTitle("AI");
			book1.setAuthor("Alex");
			book1.setPageCount(1234);
			book1.setReleaseDate("04/03/2023");
			book1.getPageCount();
			book1.getReleaseDate();
			book1.getTitle();
			string str = "Alex";
			Assert::AreEqual(book1.getAuthor(), str);
		}
		TEST_METHOD(Input_lesson)
		{
			Lesson lesson1;
			lesson1.setType("practice work");
			lesson1.setDayOfWeek("Sunday");
			lesson1.setRoom("607-5");
			lesson1.setTime("9:00");
			lesson1.setIsMissed(false);
			lesson1.setComments("be ready to the test!!");
			lesson1.getDayOfWeek();
			lesson1.getComments();
			lesson1.getIsMissed();
			lesson1.getTime();
			lesson1.getType();
			Lesson lesson2;
			lesson2.setType("practice work");
			lesson2.setDayOfWeek("Sunday");
			lesson2.setRoom("607-5");
			lesson2.setTime("10:35");
			lesson2.setIsMissed(false);
			string str = "607-5";
			Assert::AreEqual(lesson1.getRoom(), str);
		}
	};
}
