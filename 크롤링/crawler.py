import requests
import telepot
import time
import random
from bs4 import BeautifulSoup
from selenium import webdriver
from datetime import datetime

token = "********" #토큰
mc = ""  #mc

bot = telepot.Bot(token)
now = datetime.now()

driver = webdriver.Chrome('/Users/JUNHYEONG/Downloads/chromedriver')    #chromedriver 경로
driver.implicitly_wait(3)

driver.get('PUT Login URL HERE')   #로그인 URL 입력

driver.find_element_by_name('id').send_keys('아이디')  #아이디 입력
driver.find_element_by_name('pwd').send_keys('비밀번호')  #비밀번호 입력

driver.find_element_by_xpath('//*[@id="LoginForm"]/div/div/div[2]/div/div/fieldset/div/div[4]/button').click()

while True:
    now = datetime.now()

    driver.get('https://swexpertacademy.com/main/sst/common/userTestList.do?')  #정보를 얻을 URL입력

    html = driver.page_source
    soup = BeautifulSoup(html, 'html.parser')

    datas = driver.find_element_by_xpath('/html/body/div[4]/div[3]/table/tbody/tr[1]/td[5]').text

    print(now)

    if '신청중' in datas:
        bot.sendMessage(mc, text='신청가능함')

    print(datas)
    gap = random.randrange(15, 30)
    gap += random.random()
    print(gap)
    time.sleep(gap)
