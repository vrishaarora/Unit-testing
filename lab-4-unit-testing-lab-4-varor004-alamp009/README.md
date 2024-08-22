# Unit Testing

>This lab is adapted primarily from the [Google Test Primer](https://google.github.io/googletest/primer.html), [Mocking for Dummies](https://google.github.io/googletest/gmock_for_dummies.html), and [this lab](https://www.cs.sfu.ca/~wsumner/teaching/exercise-unit-tests.html). Feel free to consult these resources.

Unit Testing refers to the validation and verification of the smallest testable part of an application. It is common to make functions or classes the target of unit tests due to how simple it is to isolate them from the rest of the application. When unit testing modules that are dependent upon other parts of the application, we have to simulate those interactions. In prior labs you already had some experience with the GoogleTest framework. In this lab we are going to expand that experience by setting up multiple tests as well as simulating some aspects of an application.

## Googletest Framework
The Googletest (GTest) framework is a testing framework that Google developed for internal use, but was later released to the public. The framework's popularity is primarily due to its high compatibility with different operating systems, wide community support, and a robust toolset for building different testing scenarios. It is not the only tool for unit testing and even less so the best option for every project. The time will come for you to choose the testing framework that fits your need, but for now let us dive deeper into GTest. 

>As with every other lab, you are highly encouraged to use the CS100 development server as well as VS Code. In this lab, you will need to organize your work and distribute responsibilities. One suggestion is to dive by feature or by file.

According to GTest's own guide, unit tests should have the following qualities:

-Tests should be independent and repeatable. It’s a pain to debug a test that succeeds or fails as a result of other tests. googletest isolates the tests by running each of them on a different object. When a test fails, googletest allows you to run it in isolation for quick debugging.

-Tests should be well organized and reflect the structure of the tested code. googletest groups related tests into test suites that can share data and subroutines. This common pattern is easy to recognize and makes tests easy to maintain. Such consistency is especially helpful when people switch projects and start to work on a new code base.

-Tests should be portable and reusable. Google has a lot of code that is platform-neutral; its tests should also be platform-neutral. googletest works on different OSes, with different compilers, with or without exceptions, so googletest tests can work with a variety of configurations.

-When tests fail, they should provide as much information about the problem as possible. googletest doesn’t stop at the first test failure. Instead, it only stops the current test and continues with the next. You can also set up tests that report non-fatal failures after which the current test continues. Thus, you can detect and fix multiple bugs in a single run-edit-compile cycle.

-The testing framework should liberate test writers from housekeeping chores and let them focus on the test content. googletest automatically keeps track of all tests defined, and doesn’t require the user to enumerate them in order to run them.

-Tests should be fast. With googletest, you can reuse shared resources across tests and pay for the set-up/tear-down only once, without making tests depend on each other.

## Reviewing unit tests

Go ahead and clone this repository. You will notice that this time there is a folder called 'test'. This is the place where your tests will be stored. Currently there's just a `dummy.cpp` file that does nothing. Go ahead and add the GTest submodule form inside this folder. You have also been provided with a sample CMakeLists.txt file. You will need to modify it to add new files as well as making sure the paths are correct. To create the executable, you will need to run the cmake/make commands from your main lab directory.

> Notice that in this lab we are telling you what to do without explicitly writing the exact commands you should run. This is because you have learned how to do these steps. If you need to review how to add the GTest submodule you may want to review Lab 2.

Now is a good time to create a branch. Call this branch `TriangleTestingBranch`. After you have created that branch, follow these steps:
- Take a look at `include/Triangle.h` and `lib/Triangle.cpp`. These files have the declaration and definition of a Triangle class. There are bugs in the `getPerimeter()`, `getArea()`, and `getKind()`methods. Don't fix them!
- Create your `test.cpp` file within the `test` folder. You will create unit tests that are part of the `TriangleTests` group.
- Create at least three tests that shouldn't pass because of the bugs. In other words, passing these tests would mean the bugs are fixed.
- Create an additional test using `EXPECT_DEATH`. This test should validate that the code will terminate if invalid input is provided (see the GTest reference for more information). 
- Create at least four more tests that are part of the `TriangleTests` group. These tests should pass (one of them could be EXPECT_NOT_THROW to validate that providing three integers will not throw an exception).

> Each test should have its own function (don't add all the test to a single function). You will have to keep instantiating a Triangle object to run these test. If you use a Test Fixture it would be more efficient. However, fixtures are slightly advanced so it is up to you to do it. Refer to the GTest primer for more information on how to use fixtures.

Remember to commit and push your changes to the branch you created.

## Covering all your tracks

Create another branch from main and call it `HailstoneTestingBranch`. This branch should not have any of the work form the Triangle branch because that work has not been merged with main. Create a `test.cpp` file from within the `test` folder and don't forget to add the GTest submodule if it is not there. 

This task is rather simple. You will create Unit Tests for the `satisfiesHailstone()` function defined in `Hailstone.h` and declared in `Hailstone.cpp`. This group of tests will be called `HailstoneTests` and when running all your tests, it should cover each statement of `satisfiesHailstone`.  For example, one of the tests should use 0 as input so the `return false;` statement is executed within that test. When done, commit and push your changes to the branch.

> When testing it is important to ensure that every line of code is a target of at least one unit test. This is called Code Coverage and there are tools for automating the task of identifying code that hasn't been tested. That will be the topic for lab 6. For now you are doing a manual check.

## Google Mock

This part of the lab is going to require some research. Google Mocks or GMocks are fake classes used in testing to simulate the behavior of the real thing. We use mocks when using the real class is not feasible such as it not being developed or not being unit tested. Mocks are setup in a way that lets them know in advance what is supposed to happen during the test such as which of their methods will be invoked, and they help us by indicating whether what really happened in the test is different from what is supposed to happen. While I could tell you all about GMock, Google already put together a great starting guide for it and you can find it [here](http://google.github.io/googletest/gmock_for_dummies.html).

After carefully reading the guide for GMock, now we are going to work with the performAwardCeremony function declared in `Awards.h` and defined in `Awards.cpp`. The function takes in a list of names and gives medals to the first three in that list. Follow the next steps for this task:
- Create another branch from main and call it `AwardsTestingBranch`
- Create the `test.cpp` file from within the test folder and add the GTest submodule
- Within the test file, create a stub for RankList. A stub is a simple simulation of a class that your unit test depends on. Stubs are used in unit tests so that you do not need to immediately implement the class or because using the real class is too expensive to run (for example, a class that uses the GUI but we are testing something in the backend so we don't want to keep generating graphics during every test). To create a stub for RankList, create a dervied class from RankList and implement a simple simulation of the `getNext()` method using a hardcoded list of names.
- Create a mock for AwardCeremonyActions. It should be able to simulate the call to the following methods: `playAnthem()`, `awardBronze()`, `awardSilver()`, `awardGold()`, and `turnOffTheLightsAndGoHome()`. 
- Use the mock and stub you created to test the `performAwardCeremony` function. Generate at least one unit test to ensure that the function is running correctly. Your test should ensure that the function calls the following methods in exactly this order: `playAnthem()`, `awardBronze()`, `awardSilver()`, `awardGold()`, and `turnOffTheLightsAndGoHome()`. Notice that the award methods (bronze, silver and gold) expect a name to be passed. This should be in the same order they are read form the rank list. The name for this test group is `AwardsTests`.
- Commit and push your changes to the branch

## Final task

You are almost there. For your final task you will merge your branches with main. You are bound to have conflicts (because you have three different `test.cpp`). You have two options:
- Solve the merging conflicts and create a merged `test.cpp` with all the tests from the three branches.
- Rename the `test.cpp` files

Pick any of these two and be ready to explain why you chose that option during your demo. Do not delete the merged branches until after your demo (when a branch is successfully merged it should be deleted but we want to see your work).





