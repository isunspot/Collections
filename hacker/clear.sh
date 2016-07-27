#!/bin/sh

sudo sed -i '/sudo.*heyu/d' /var/log/secure
sudo sed -i '/root.*heyu/d' /var/log/secure
sudo sed -i '/sudo.*heyu/d' /var/log/messages
sudo sed -i '/root.*heyu/d' /var/log/messages
