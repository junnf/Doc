from sqlalchemy import Column, String, create_engine
from sqlalchemy import INT
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class Member(Base):
    __tablename__ = 'member'

    #id_num = Column(String(20))
    name = Column(String(20))


engine = create_engine('mysql+mysqlconnector://root:ljn7168396123@localhost:3306/test')
DBSession = sessionmaker(bind=engine) 
session = DBSession()
new_member = Member(id_num=5,name='asd')
session.add(new_member)
session.commit()
session.close()

