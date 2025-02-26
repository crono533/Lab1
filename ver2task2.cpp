#include <iostream>
#include <string>
#include <memory>

class Image {
public:
	int height;
	int width;

	Image() {
		height = 0;
		width = 0;
	};

	Image(int height, int width) : height(height), width(width) {}

};

class Account {
public:
	static int countId;
	int id;

	Account() {
		countId++;
		id = countId;
	};

	Account(int id) : id(id) {}

	~Account()
	{
		countId--;
	}

};

int Account::countId = 0;

class Url {
public:
	std::string url;

	Url() {
		url = "";
	}

	Url(const std::string& url) : url(url) {}
	

};

class ImageMemoryActions 
{
public:
	static void Save(const Image& image)
	{

		// сохранение изображение в файловой системе 
		std::cout << "сохранение изображение в файловой системе" << std::endl;
	}
	static int DeleteDuplicates()
	{
		// удалить из файловой системы все дублирующиеся изображения и вернуть количество удаленных
		std::cout << " удалить из файловой системы все дублирующиеся изображения" << std::endl;
		int count = 1;
		return count;
	}
};

class ImageActionOnImage
{
public:
	static Image Resize(Image& image, int height, int width)
	{
		// изменение размеров изображения
		std::cout << "сохранение изображение в файловой системе" << std::endl;
		return image;

	}
	static Image InvertColors(Image& image)
	{
		// выполнить инверсию цвета
		std::cout << "инверсия цвета" << std::endl;
		return image;
	}
};

class ImageDownloader
{
public:
	static std::unique_ptr<char[]> Download(const Url& imageUrl)
	{
		// загрузка байтового массива с изображением с помощью HTTP запроса
		std::cout << "загрузка изображения" << std::endl;
		std::unique_ptr<char[]> bytes(new char[10]);

		return bytes;
	}
};

class ImageAsAccountPicture
{
public:
	static Image SetImageAsAccountPicture(const Image& image, Account& account)
	{
		// запрос к базе данных для сохранения ссылки на это изображение для пользователя
		Image newPic;
		std::cout << "новая картинка для аккаунта " << account.id <<std::endl;
		return newPic;
	}
};



int main()
{
	setlocale(LC_ALL, "Rus");
	Account newAccountOne;
	Account newAccountTwo;
	Image pic;
	Url pic2("/somepic");

	ImageMemoryActions::Save(pic);
	ImageMemoryActions::DeleteDuplicates();

	std::unique_ptr<char[]> bytes = ImageDownloader::Download(pic2);

	ImageAsAccountPicture::SetImageAsAccountPicture(pic, newAccountOne);
	ImageAsAccountPicture::SetImageAsAccountPicture(pic, newAccountTwo);

	ImageActionOnImage::Resize(pic, 10, 30);
	ImageActionOnImage::InvertColors(pic);

	return 0;
}

