#include "Txt.h"

namespace l1
{
	Txt::Txt()
	{
		buf_size = 0;
		str_buf = NULL;

	}
	Txt::Txt(Txt& copy_obj)
	{
		fcopy(copy_obj);
	}
	Txt::Txt(Txt&& move_obj)
	{
		fmove(std::move(move_obj));
	}

	Txt& Txt::operator = (Txt & copy_obj)
	{
		if (this == &copy_obj)
		{
			return *this;
		}
		if (this->str_buf != NULL)
		{
			delete[] this->str_buf;
		}
		fcopy(copy_obj);
		return *this;
		
	}
	Txt& Txt::operator = (Txt&& move_obj)
	{
		if (this == &move_obj)
		{
			return *this;
		}
		if (this->str_buf != NULL)
		{
			delete[] this->str_buf;
		}
		fmove(std::move(move_obj));
		return *this;
	}


	Txt::Txt(const char * filename)
	{
		buf_size = 0;
		load_context(filename);
	}
	Txt::~Txt()
	{
		if (str_buf != NULL)
		{
			if (file.is_open())
			{
				file.close();
			}
			buf_size = 0;
			delete[] str_buf;
		}
	}
	void Txt::fcopy(Txt & copy)
	{
		buf_size = copy.buf_size;
		str_buf = new std::string[buf_size]();
		for (int i = 0; i < copy.buf_size; i++)
		{
			str_buf[i] = copy.str_buf[i];
		}
	}
	void Txt::fmove(Txt && move_obj)
	{
		buf_size = move_obj.buf_size;
		str_buf = move_obj.str_buf;
		move_obj.str_buf = NULL;
		move_obj.buf_size = 0;
	}
	void Txt::count()
	{
		std::string str;
		while (std::getline(file, str))
		{
			++buf_size;
		}
		
	
	}
	void Txt::load()
	{
		int index = 0;
		while (std::getline(file,str_buf[index]))
		{
			
			++index;

		}
	}

	size_t Txt::size() const
	{
		return buf_size;
	}
	void Txt::load_context(const char* filename)
	{
		
		file.open(filename);
		if (!file.is_open())
		{
			buf_size = 0;
			str_buf = NULL;
			return;
		}
		
		count();
		
		file.clear();
		file.seekg(0);
		str_buf = new std::string [buf_size]();
		load();
		file.close();
		
	}
}