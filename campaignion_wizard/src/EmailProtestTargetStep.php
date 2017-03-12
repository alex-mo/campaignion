<?php

namespace Drupal\campaignion_wizard;

use \Drupal\campaignion\Forms\EntityFieldForm;

class EmailProtestTargetStep extends WizardStep {

  protected $step  = 'target';
  protected $title = 'Target';

  protected $fieldForm = NULL;

  public function stepForm($form, &$form_state) {

    $form = parent::stepForm($form, $form_state);

    $this->fieldForm = new EntityFieldForm('node', $this->wizard->node, array('field_protest_target_options', 'field_protest_target'));
    $form += $this->fieldForm->formArray($form_state);

    return $form;
  }

  public function validateStep($form, &$form_state) {
    $this->fieldForm->validate($form, $form_state);

    $has_target = FALSE;
    foreach ($form_state['values']['field_protest_target']['und'] as $delta => $values) {
      if (is_numeric($delta) && !empty($form_state['values']['field_protest_target']['und'][$delta]['email_protest_target']['email'])) {
        $has_target = TRUE;
        break;
      }
    }
    if ($has_target == FALSE) {
      form_error($target['email'], t('You have to specify at least 1 target.'));
    }
  }

  public function submitStep($form, &$form_state) {
    $this->fieldForm->submit($form, $form_state);
  }

  public function checkDependencies() {
    return isset($this->wizard->node->nid);
  }
}

