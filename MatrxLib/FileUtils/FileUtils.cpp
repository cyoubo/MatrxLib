#include "FileUtils.h"
FileUtils::FileUtils(void)
{}

FileUtils::FileUtils(std::string path,std::string name)
{
	this->mFilepath=path;
	int index=name.rfind('.');
	if(index!=std::string::npos)
	{
		this->mFilename=name.substr(0,index);
		this->mExtension=name.substr(index+1);
	}
	else
	{
		this->mExtension="";
	}
}

FileUtils::FileUtils(std::string fullpath)
{
	int index=fullpath.find_last_of('\\');
	if(index!=std::string::npos)
	{
		std::string path=fullpath.substr(0,index+1);
		std::string name=fullpath.substr(index+1);

		this->mFilepath=path;

		int index=name.rfind('.');
		if(index!=std::string::npos)
		{
			this->mFilename=name.substr(0,index);
			this->mExtension=name.substr(index+1);
		}
		else
		{
			this->mExtension="";
		}
		
	}

}

FileUtils::~FileUtils(void)
{
	if(this->out)
		out.close();
	if(this->input)
		input.close();
}

std::string FileUtils::CombinePath()
{
	return this->mFilepath+this->mFilename+"."+this->mExtension;;
}

std::string FileUtils::CombinePath(int i)
{
	char t[20];
	_itoa_s(i,t,20);
	return  this->mFilepath+"\\"+"\\"+this->mFilename+"_"+t+"."+this->mExtension;
}

std::string FileUtils::FileName()
{
	return this->mFilename;
}

std::string FileUtils::FilePath()
{
	return this->mFilepath;
}
std::string FileUtils::FileExtension()
{
	return this->mExtension;
}

bool FileUtils::OpenFile_ForRead()
{
	FileUtils t(this->CombinePath());
	if(t.IsExist())
	{
		input.open(this->CombinePath(),std::ios::in);
		return !(input.fail());
	}
	else
	{
		return false;
	}
}

bool FileUtils::CreateOrOpenFile_ForWrite(openmode mode)
{
	
	switch(mode)
	{
		case Maintain:
			{
				std::ofstream tempout(this->CombinePath(),std::ios::out);
				bool r=tempout.is_open();
				if(r)
				{
					int i=1;
					while(r)
					{
						tempout.close();
						tempout.open(this->CombinePath((i++)),std::ios::_Nocreate);
						r=tempout.is_open();
					}
					out.open(this->CombinePath(--i),std::ios::out);
				}
				else
					{
						out.open(this->CombinePath(),std::ios::out);
					}
				tempout.close();
			}break;
		case Override:
			{
				out.open(this->CombinePath(),std::ios::trunc);
			}break;
		case Append:
			{
				out.open(this->CombinePath(),std::ios::app|std::ios::out);
			}break;
	}

	return out.is_open();
}

void FileUtils::Close()
{
	if(this->out.is_open())
		out.close();
}

bool FileUtils::IsExist(std::string fullstring)
{
	std::ifstream t(fullstring);
	bool r=t.is_open();
	t.close();
	return r;
}

bool FileUtils::IsExist()
{
	std::ifstream t(this->CombinePath());
	bool r=t.is_open();
	t.close();
	return r;
}

bool FileUtils::SplitFullPath(std::string fullpath,std::string &out_filepath,std::string &out_filename)
{
	FileUtils t(fullpath);
	out_filepath=t.FilePath();
	out_filename=t.FileName();

	return true;
}

bool FileUtils::Print(bool (*printlistenr)(std::ofstream &out))
{
	return printlistenr(this->out);
}

bool FileUtils::Print(BaseOuterListener* listener)
{
	bool r=listener->print(this->out);
	return r;
}

bool FileUtils::Scan(BaseInputListener* listener)
{
	return listener->scan(this->input);
}
