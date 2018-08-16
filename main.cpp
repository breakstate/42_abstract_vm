# include "./hdr/AVM.hpp"

int main(int argc, char** argv) {
	try{
		AVM run;
		run.run(argc, argv);
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}

	return (0);
}
