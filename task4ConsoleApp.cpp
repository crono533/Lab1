#include <iostream>
#include <memory>

class AbstractEntity
{
public:
	virtual ~AbstractEntity() = 0;
};

AbstractEntity::~AbstractEntity()
{
}

class AccountEntity : public AbstractEntity
{


};

class RoleEntity : public AbstractEntity
{

};

class NewEntity : public AbstractEntity
{

};


class IRepository
{
public:
	virtual void Save(std::shared_ptr<AbstractEntity> entity) = 0;
};

class AccountRoleRepository : public IRepository
{
public:
	void Save(std::shared_ptr<AbstractEntity> entity_) override
	{
		std::shared_ptr<AccountEntity> accountEntity = std::dynamic_pointer_cast<AccountEntity>(entity_);
		if (accountEntity != nullptr)
		{
			std::cout << "Обнаружена сущность Account" << std::endl << "делаем действия..." << std::endl;
		}

		std::shared_ptr<RoleEntity> roleEntity = std::dynamic_pointer_cast<RoleEntity>(entity_);
		if (roleEntity != nullptr)
		{
			std::cout << "Обнаружена сущность Role" << std::endl << "делаем действия..." << std::endl;
		}
	}
};

class NewRepository : IRepository
{
	void Save(std::shared_ptr<AbstractEntity> entity_) override
	{
		std::shared_ptr<NewEntity> newEntity = std::dynamic_pointer_cast<NewEntity>(entity_);
		if (newEntity != nullptr)
		{
			std::cout << "Обнаружена сущность New" << std::endl << "делаем действия...";
		}

	}
};

int main()
{
	setlocale(LC_ALL, "Rus");

	//попробовть создать указатель обычный на сущнсть аккаунта и сделать ещё shared внизу,
	//после попробовать удалить обычный указатель и проверить остался ли тот самый объект жив в shared


	std::shared_ptr<AbstractEntity> entity = std::make_shared<AccountEntity>();
	AccountRoleRepository repo;
	repo.Save(entity);

}
