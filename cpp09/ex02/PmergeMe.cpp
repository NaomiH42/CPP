#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** input)
{
	struct timeval timeb, timea;
	gettimeofday(&timeb, NULL);
	putIn(input);
	sortPairs();
	_set = sortFakeRecursive(_set);
	sortB();
	gettimeofday(&timea, NULL);
	std::cout << "Before: ";
	for (int i = 1; input[i]; i++)
		std::cout << input[i] << " ";
	std::cout << "\nAfter: ";
	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
		std::cout << it->first << " ";
	std::cout << "\nTime to process a range of " << _set.size() << " elements with std::vector<pair>: ";
	std::cout << timea.tv_usec - timeb.tv_usec << "\n";
	putInLst(input);
	gettimeofday(&timeb, NULL);
	sortPairsLst();
	Lists lsts;
	lsts.list1 = _listA;
	lsts.list2 = _listB;
	lsts = sortRecurLst(lsts);
	_listA = lsts.list1;
	_listB = lsts.list2;
	putInA();
	gettimeofday(&timea, NULL);
	std::cout << "Time to process a range of " << _set.size() << " elements with std::list: ";
	std::cout << timea.tv_usec - timeb.tv_usec << "\n";
}

void PmergeMe::printLst()
{
	for (std::list<int>::iterator it = _listA.begin(); it != _listA.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	for (std::list<int>::iterator it = _listB.begin(); it != _listB.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::get()
{
	return (_set);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& o)
{
	this->_set = o._set;
	this->_listA = o._listA;
	this->_listB = o._listB;
}

PmergeMe&PmergeMe::operator=(const PmergeMe& o)
{
	if (this != &o)
	{
		this->_set = o._set;
		this->_listA = o._listA;
		this->_listB = o._listB;
	}
	return *this;
}

int	PmergeMe::findPosMerge(std::vector<std::pair<int, int> > vec, int num)
{
	int i = 0;
	for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it->first <= num)
			break;
		i++;
	}
	return (i);
}

std::vector<std::pair<int, int> >	PmergeMe::mergeVectors(std::vector<std::pair<int, int> > vec1, std::vector<std::pair<int, int> > vec2) {
	std::vector<std::pair<int, int> > vec;
	for (unsigned long i = 0; i < vec1.size(); i++) {
		vec.insert(vec.begin() + findPosMerge(vec, vec1.at(i).first), vec1.at(i));
	}
	for (unsigned long i = 0; i < vec2.size(); i++) {
		vec.insert(vec.begin() + findPosMerge(vec, vec2.at(i).first), vec2.at(i));
	}
	return vec;
}

std::vector<std::pair<int, int> >	PmergeMe::sortFakeRecursive(std::vector<std::pair<int, int> > vec)
{
	if (vec.size() == 1) return vec;
	if (vec.size() == 2) {
		if (vec.at(0).first < vec.at(1).first) {
			int temp = vec.at(0).first;
			int tempB = vec.at(0).second;
			vec.at(0).first = vec.at(1).first;
			vec.at(0).second = vec.at(1).second;
			vec.at(1).first = temp;
			vec.at(1).second = tempB;
		}
		return vec;
	}
	std::vector<std::pair<int, int> > vec1;
	std::vector<std::pair<int, int> > vec2;
	for (unsigned long i = 0; i < vec.size(); i++) {
		if (i % 2 == 0) {
			vec1.push_back(vec.at(i));
		}
		else vec2.push_back(vec.at(i));
	}
	vec1 = sortFakeRecursive(vec1);
	vec2 = sortFakeRecursive(vec2);
	vec = mergeVectors(vec1, vec2);
	return vec;
}

Lists PmergeMe::mergeLists(Lists lsts1, Lists lsts2) {
    Lists lst;
    while (!lsts1.list1.empty() && !lsts2.list1.empty()) {
        if (lsts1.list1.front() >= lsts2.list1.front()) {
            lst.list1.push_back(lsts1.list1.front());
            lst.list2.push_back(lsts1.list2.front());
            lsts1.list1.pop_front();
            lsts1.list2.pop_front();
        } else {
            lst.list1.push_back(lsts2.list1.front());
            lst.list2.push_back(lsts2.list2.front());
            lsts2.list1.pop_front();
            lsts2.list2.pop_front();
        }
    }
    while (!lsts1.list1.empty()) {
        lst.list1.push_back(lsts1.list1.front());
        lst.list2.push_back(lsts1.list2.front());
        lsts1.list1.pop_front();
        lsts1.list2.pop_front();
    }
    while (!lsts2.list1.empty()) {
        lst.list1.push_back(lsts2.list1.front());
        lst.list2.push_back(lsts2.list2.front());
        lsts2.list1.pop_front();
        lsts2.list2.pop_front();
    }
    return lst;
}

Lists PmergeMe::sortRecurLst(Lists lsts)
{
    if (lsts.list1.size() <= 1) return lsts;
    if (lsts.list1.size() == 2) {
        if (lsts.list1.front() < lsts.list1.back()) {
            std::swap(lsts.list1.front(), lsts.list1.back());
            std::swap(lsts.list2.front(), lsts.list2.back());
        }
        return lsts;
    }
    Lists lst1;
    Lists lst2;
    unsigned long mid = lsts.list1.size() / 2;
    unsigned long i = 0;
    while (!lsts.list1.empty()) {
        if (i < mid) {
            lst1.list1.push_back(lsts.list1.front());
            lst1.list2.push_back(lsts.list2.front());
        } else {
            lst2.list1.push_back(lsts.list1.front());
            lst2.list2.push_back(lsts.list2.front());
        }
        lsts.list1.pop_front();
        lsts.list2.pop_front();
        i++;
    }
    lst1 = sortRecurLst(lst1);
    lst2 = sortRecurLst(lst2);
    lsts = mergeLists(lst1, lst2);
    return lsts;
}

bool PmergeMe::isSorted()
{
	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (it->second != -1)
			return (false);
	}
	return (true);
}

std::list<int>::iterator	PmergeMe::findPosLst(int num)
{
	for (std::list<int>::iterator it = _listA.begin(); it != _listA.end(); it++)
	{
		if (*it <= num)
			return (it);
	}
	return (_listA.end());
}

void PmergeMe::putInA()
{
	for (std::list<int>::iterator it = _listB.begin(); it != _listB.end(); it++)
	{
		_listA.insert(findPosLst(*it), *it);
	}
	if (_size % 2 == 0)
		_listA.pop_back();
}

int	PmergeMe::findPos(int num)
{
	int i = 0;
	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (it->first <= num)
			break;
		i++;
	}
	return (i);
}

void PmergeMe::sortB()
{
	int i = 0;
	int num = 0;

	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (it->second != -1)
		{
			i = findPos(it->second);
			num = it->second;
			it->second = -1;
			break;
		}
	}
	_set.insert(_set.begin() + i, std::make_pair(num, -1));
	if (!isSorted())
		sortB();
	else if (_size % 2 == 0)
		_set.pop_back();

}

void PmergeMe::sortPairs()
{
	for (std::vector<std::pair<int, int> >::iterator it = _set.begin(); it != _set.end(); it++)
	{
		if (it->first < it->second && it->first != -1)
		{
			int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void PmergeMe::putIn(char **input)
{
	int i = 1;
	while (input[i])
	{
		std::string number = input[i];
		if (input[i+1])
		{
			std::string number2 = input[i + 1];
			_set.push_back(std::make_pair(strToInt(number), strToInt(number2)));
			i += 2;
		}
		else
		{
			_set.push_back(std::make_pair(-1, strToInt(number)));
			i++;
		}
	}
	_size = i;
}

void PmergeMe::sortPairsLst()
{
	std::list<int>::iterator itA = _listA.begin();
	std::list<int>::iterator itB = _listB.begin();
	while (itA != _listA.end())
	{
		if (*itA < *itB && *itA != -1)
		{
			int temp = *itA;
			*itA = *itB;
			*itB = temp;
		}
		itA++;
		itB++;
	}
}

void PmergeMe::putInLst(char **input)
{
	int i = 1;
	while (input[i])
	{
		std::string number = input[i];
		if (input[i+1])
		{
			std::string number2 = input[i + 1];
			_listA.insert(_listA.begin(), strToInt(number));
			_listB.insert(_listB.begin(), strToInt(number2));
			i += 2;
		}
		else
		{
			_listB.insert(_listB.begin(), strToInt(number));
			_listA.insert(_listA.begin(), -1);
			i++;
		}
	}
	_size = i;
}

int strToInt(std::string str)
{
	int result;
	std::stringstream ss(str);
	ss >> result;
	return (result);
}

// 578 457 252 177 602 944 415 476 153 690 498 117 477 996 642 739 876 833 779 172 959 574 512 567 462 335 236 286 364 794 149 520 326 403 782 389 905 475 927 95 805 273 61 128 599 765 644 483 737 595 709 386 664 499 416 47 717 6 56 376 738 438 854 874 75 831 392 255 631 378 555 347 953 516 680 988 166 237 57 108 922 383 985 107 519 587 966 981 291 13 48 658 445 418 182 593 798 58 745 674 119 331 994 908 933 979 278 708 503 116 193 684 884 280 404 91 464 957 776 681 671 375 284 225 965 191 46 51 646 691 718 240 712 294 729 926 722 337 266 352 735 694 241 493 525 311 367 330 43 747 247 217 716 925 612 668 269 189 770 479 52 88 113 609 627 720 123 579 62 626 195 169 69 40 628 8 440 591 852 608 165 537 154 245 974 654 370 841 951 329 882 931 216 838 436 605 821 426 903 622 751 835 872 351 559 864 582 707 590 365 629 869 962 421 657 989 767 423 695 806 304 586 634 206 778 140 802 249 783 890 270 85 345 137 393 30 157 973 98 799 743 162 800 103 676 19 528 978 596 777 120 955 986 640 569 983 295 360 573 459 473 554 775 746 349 823 863 230 706 316 891 653 104 99 704 768 552 384 726 212 577 410 604 64 277 285 1000 961 740 812 618 906 22 127 131 470 613 402 566 878 156 894 53 257 59 803 456 580 526 856 288 685 811 594 719 97 188 508 752 667 411 987 871 771 319 592 41 980 505 126 395 563 442 865 787 949 73 755 276 466 764 893 721 379 336 471 715 167 485 553 488 256 12 430 504 63 733 235 387 701 232 804 2 377 623 947 45 964 611 373 850 265 527 310 859 670 125 999 190 454 341 24 572 603 666 215 443 796 86 202 78 543 100 648 382 325 941 660 207 809 606 625 895 228 928 921 774 37 638 173 205 275 523 181 936 757 139 492 870 536 750 952 940 314 907 396 732 934 995 881 16 320 860 5 96 885 784 315 303 260 455 343 575 899 142 494 299 248 400 643 923 759 451 547 915 318 71 21 673 60 904 619 478 267 819 917 38 346 541 425 342 588 287 355 282 797 87 328 971 645 868 218 535 26 950 447 305 896 428 219 298 368 406 902 786 65 912 239 639 44 55 70 990 441 496 992 773 669 621 242 25 412 264 665 533 633 302 813 589 758 408 935 9 147 11 736 827 692 538 361 327 647 687 309 976 427 148 848 110 413 39 200 465 358 27 178 199 568 506 394 731 81 830 74 484 984 801 118 7 624 79 963 469 730 381 50 635 308 703 82 34 585 94 359 83 734 84 900 372 114 560 514 164 723 818 388 724 3 652 54 171 656 636 1 790 689 186 711 584 772 958 938 158 405 688 452 254 780 760 143 550 434 432 889 369 754 363 353 880 511 713 534 919 571 531 875 948 632 814 385 101 913 323 766 89 522 832 887 161 756 184 843 630 437 435 614 828 620 497 788 698 23 258 17 792 263 138 155 211 822 663 35 458 840 517 861 548 197 129 682 672 122 234 583 448 789 744 991 339 259 546 610 223 233 422 542 334 742 918 187 102 829 877 196 491 238 450 306 354 344 524 649 659 36 144 272 693 598 151 824 179 417 932 867 29 702 433 115 198 80 714 419 208 699 229 793 20 220 429 937 532 4 753 10 748 781 677 705 152 879 409 357 920 261 942 175 15 210 556 301 696 246 398 467 380 518 397 399 898 424 348 615 340 109 655 487 727 290 679 213 825 998 90 761 68 268 969 176 183 468 338 204 924 472 846 808 858 333 601 221 226 121 150 296 911 549 76 227 844 42 576 312 146 749 49 371 292 274 297 180 857 481 124 997 561 317 362 661 946 564 262 132 956 32 888 350 725 545 145 185 224 374 279 507 529 678 967 414 486 324 697 510 111 866 174 855 495 332 982 168 105 444 873 106 539 600 810 862 562 170 231 530 460 975 446 300 960 33 391 67 551 93 834 977 662 929 817 883 482 849 321 66 901 816 842 194 281 675 489 617 972 401 130 449 490 762 853 509 836 480 253 461 785 356 930 293 159 463 72 313 581 243 909 683 289 710 807 407 134 616 945 943 77 916 557 769 651 544 135 540 837 521 251 192 112 500 839 203 728 390 607 136 28 826 892 501 650 815 791 453 886 910 141 222 914 763 515 250 271 954 847 970 163 570 307 820 244 502 31 474 18 209 968 366 700 686 214 897 637 939 420 993 565 439 597 133 201 851 641 558 283 845 14 322 431 92 741 513 160 795
