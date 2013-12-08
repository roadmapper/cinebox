static unsigned char translate_code(int code) {
	switch (code) {
	case 21:
		return 'q';
		break;
	case 29:
		return 'w';
		break;
	case 36:
		return 'e';
		break;
	case 45:
		return 'r';
		break;
	case 44:
		return 't';
		break;
	case 53:
		return 'y';
		break;
	case 60:
		return 'u';
		break;
	case 67:
		return 'i';
		break;
	case 68:
		return 'o';
		break;
	case 77:
		return 'p';
		break;
	case 28:
		return 'a';
		break;
	case 27:
		return 's';
		break;
	case 35:
		return 'd';
		break;
	case 43:
		return 'f';
		break;
	case 52:
		return 'g';
		break;
	case 51:
		return 'h';
		break;
	case 59:
		return 'j';
		break;
	case 66:
		return 'k';
		break;
	case 75:
		return 'l';
		break;
	case 26:
		return 'z';
		break;
	case 34:
		return 'x';
		break;
	case 33:
		return 'c';
		break;
	case 42:
		return 'v';
		break;
	case 50:
		return 'b';
		break;
	case 49:
		return 'n';
		break;
	case 58:
		return 'm';
		break;
	case 22:
		return '1';
		break;
	case 30:
		return '2';
		break;
	case 38:
		return '3';
		break;
	case 37:
		return '4';
		break;
	case 46:
		return '5';
		break;
	case 54:
		return '6';
		break;
	case 61:
		return '7';
		break;
	case 62:
		return '8';
		break;
	case 70:
		return '9';
		break;
	case 69:
		return '0';
		break;
	case 117:
		return 'â†‘'; //↑
		break;
	case 107:
		return 'â†�'; //←
		break;
	case 114:
		return 'â†’'; //↓
		break;
	case 116:
		return '→'; //→
		break;
	case 41:
		return ' ';
		break;
	case 73:
		return '.';
		break;
	case 65:
		return ',';
		break;
	case 74:
		return '?';
		break;
	case 18:
		return '!';
		break;
	case 90:
		return '\n';
		break;
	case 102:
		return '\b';
		break;
	default:
		return '\0';
	}
}
