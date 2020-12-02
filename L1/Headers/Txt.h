#pragma once

#include <fstream>
#include <sstream>
#include <string>
namespace l1
{
	class Txt
	{
	private:
		std::string * str_buf;
		size_t buf_size;
		std::ifstream file;
		void load_context(const char* filename);
		void count();
		void load();
		void fcopy(Txt & copy_obj);
		void fmove(Txt && move_obj);

	public:
		Txt();
		~Txt();
		Txt(const char* filename);
		Txt(Txt& left);
		Txt(Txt&& left);
		size_t size() const;
		Txt& operator = (Txt & left);
		Txt& operator = (Txt && left);
		

	};

}

