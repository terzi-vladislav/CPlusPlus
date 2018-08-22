#include <iostream>
         
 struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
 protected:
    Foo(const char *msg) : msg(msg) {}
 private:
    const char *msg;
 };

 struct FooTwin : public Foo {
 	FooTwin(const char *msg) : Foo(msg) {}
 };

 void foo_says(const Foo &foo) {
 	foo.say();
 }

 Foo get_foo(const char *msg) {
 	FooTwin fooTwinObject(msg);
 	Foo *fooObject = &fooTwinObject;
 	return *fooObject;
 }

 int main() {
 	foo_says(get_foo("Hello!"));
 }