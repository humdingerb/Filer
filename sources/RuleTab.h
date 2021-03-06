/*
 * Copyright 2008, 2016. All rights reserved.
 * Distributed under the terms of the MIT license.
 *
 * Authors:
 *  DarkWyrm <darkwyrm@gmail.com>, Copyright 2008
 *	Humdinger, humdingerb@gmail.com
 */
#ifndef RULETAB_H
#define RULETAB_H

#include <Button.h>
#include <CheckBox.h>
#include <ListView.h>
#include <View.h>

#include "AddRemoveButtons.h"
#include "RuleItemList.h"
#include "ObjectList.h"

class RuleItem;
class FilerRule;

class RuleTab : public BView
{
public:
					RuleTab();
					~RuleTab();

	virtual void	AttachedToWindow();
	void			MessageReceived(BMessage* message);
	void			UpdateRuleWindowPos(BRect pos);
	
private:
	void			_BuildLayout();
	void			UpdateButtons();

	void			AddRule(FilerRule* rule);
	void			RemoveRule(int32 selection);

	BObjectList<FilerRule>*fRuleList;

	BCheckBox*		fMatchBox;

	BButton*		fEditButton;
	BButton*		fDisableButton;
	BButton*		fMoveUpButton;
	BButton*		fMoveDownButton;

	AddRemoveButtons*	fAddRemoveButtons;

	RuleItemList*	fRuleItemList;
	BScrollView*	fScrollView;
	bool			fChanges;
	BRect			fRulePos;
};


#endif // RULETAB_H
